
/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
使用迭代和递归方法分别实现
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
ListNode* reverseList(ListNode* head) {
    // 迭代实现
    if (head == nullptr || head->next == nullptr) {
        // 0个或1个节点，直接返回
        return head;
    }

    auto p(head);

    while (p->next != nullptr) {
        auto pnn(p->next->next);
        p->next->next = head;   // 当前节点指向第一个节点
        head = p->next;         // 头节点更新为当前一个节点
        p->next = pnn;          // 当前节点前一个节点指向当前节点后一个节点
    }

    return head;
}
*/

ListNode* reverseList(ListNode* head) {
    // 递归实现
    // 相当于已最后一个节点为最终头节点
    // 所有节点的指针反向
    if (head == nullptr || head->next == nullptr) {
        // 0个或1个节点，直接返回
        return head;
    }

    auto last(reverseList(head->next));
    head->next->next = head;
    head->next = nullptr;

    return last;
}
