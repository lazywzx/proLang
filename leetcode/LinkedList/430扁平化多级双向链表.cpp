/*
你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针 。
这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。
这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构 。
给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。
让 curr 是一个带有子列表的节点。
子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。
*/

class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};


Node* flatten_func(Node* head) {
    // 扁平化多级链表实现
    auto p(head);
    // 找到child非空的节点
    while (p->next != nullptr) {
        if (p->child != nullptr) {
            auto tail(flatten_func(p->child));
            // 对p节点处进行扁平化
            p->next->prev = tail;
            tail->next = p->next;
            p->child->prev = p;
            p->next = p->child;
            p->child = nullptr;
            // 跳到本层原来的下一个节点
            p = tail->next;
        }
        else {
            p = p->next;
        }
    }

    // p指向最后一个节点
    if (p->child != nullptr) {
        auto tail(flatten_func(p->child));
        p->child->prev = p;
        p->next = p->child;
        p->child = nullptr;
        // p指向扁平化后的最后一个节点
        p = tail;
    }
    
    return p;
}


Node* flatten(Node* head) {
    if (head == nullptr) {
        return head;
    }

    flatten_func(head);

    return head;
}
