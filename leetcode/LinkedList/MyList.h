#ifndef MYLIST_H_
#define MYLIST_H_

// #include <memory>

using namespace std;

/* 带头节点MyList类 */
class MyLinkedList {
    private:
        // 数据成员
        int val;    // 在头节点中用于记录链表长度
        // shared_ptr<MyLinkedList> next;   // 智能指针时间、空间效率双低！
        MyLinkedList* next;
    public:
        // 构造函数声明
        MyLinkedList(void);
        MyLinkedList(int v);

        // 成员函数声明
        int get(int index);
        void addAtHead(int v);
        void addAtTail(int v);
        void addAtIndex(int index, int v);
        void deleteAtIndex(int index);
};


/* 构造函数定义 */
MyLinkedList::MyLinkedList(void) {
    val = 0;
    next = NULL;
}

MyLinkedList::MyLinkedList(int v) {
    val = v;
    next = NULL;
}


/* 成员函数定义 */
void MyLinkedList::addAtHead(int v) {
    // 在头部添加结点
    addAtIndex(0, v);
}

void MyLinkedList::addAtTail(int v) {
    // 在尾部添加结点
    addAtIndex(val, v);
}

void MyLinkedList::addAtIndex(int index, int v) {
    // 在索引index前添加结点
    if (index <= 0) {
        // auto node = make_shared<MyLinkedList>(v);   // 动态创建一块内存并初始化，返回指向该结点的指针
        MyLinkedList* node = new MyLinkedList(v);
        node->next = next;  // 新结点指向原来的头节点
        next = node;    // 更新头节点
        ++ val;  // 更新链表长度，始终保持链表长度存储在头节点
    }
    else if (index == val) {
        // auto node = make_shared<MyLinkedList>(v);
        MyLinkedList* node = new MyLinkedList(v);
        node->next = NULL;

        if (val == 0) {
            addAtHead(v);
        }
        else {
            auto tail_ptr(next);
            while (tail_ptr->next != NULL) {
                // 寻找尾指针
                tail_ptr = tail_ptr->next;
            }
            tail_ptr->next = node;  // 更新尾指针
            ++ val;
        }
    }
    else if (index < val) {
        // auto node = make_shared<MyLinkedList>(v);
        MyLinkedList* node = new MyLinkedList(v);
        auto index_ptr(next);
        for (int i(0); i != index - 1; ++ i) {
            index_ptr = index_ptr->next;
        }

        node->next = index_ptr->next;
        index_ptr->next = node;

        ++ val;
    }
}

void MyLinkedList::deleteAtIndex(int index) {
    // 删除index索引处的结点
    if (index == 0) {
        next = next->next;
        -- val;
    }
    else if (index > 0 && index < val) {
        auto index_ptr(next);
        for (int i(0); i != index - 1; ++ i) {
            index_ptr = index_ptr->next;
        }

        index_ptr->next = index_ptr->next->next;
        -- val;
    }
}

int MyLinkedList::get(int index) {
    // 返回索引index处的数据值
    if (index < 0 || index >= val) {
        return -1;
    }

    auto index_ptr(next);
    for (int i(0); i != index; ++ i) {
        index_ptr = index_ptr->next;
    }

    return index_ptr->val;
}

#endif
