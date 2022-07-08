#include <iostream>
#include "MyList.h"

using namespace std;

// 设计一个自己的链表数据结构并实现基本操作

int main() {
    MyLinkedList* obj = new MyLinkedList();
    
    // 空链表返回值
    auto val = obj->get(3);
    cout << val << endl;
    obj->addAtTail(7);
    obj->addAtHead(1);
    obj->addAtHead(6);
    obj->addAtTail(8);
    obj->addAtTail(3);
    obj->addAtIndex(2, 0);
    obj->addAtIndex(0, 4);
    obj->addAtIndex(10, 9);
    obj->addAtIndex(6, 6);
    obj->deleteAtIndex(2);

    val = obj->get(5);
    cout << val << endl;

    // 打印链表
    int i(0);
    while (obj->get(i) != -1) {
        cout << obj->get(i) << " ";
        ++ i;
    }
    cout << endl;

    return 0;
}
