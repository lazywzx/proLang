
/*
给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeElements(ListNode* head, int val) {
    // 移除链表中指定值的元素
    if (head == nullptr) {
        return head;
    }

    // 先删除开头的val节点
    while (head != nullptr && head->val == val) {
        head = head->next;
    }

    // 判断全部都删除的特殊情况
    if (head == nullptr) {
        return head;
    }
    
    // 删除中间的val
    auto p(head);
    while (p->next != nullptr) {
        if (p->next->val == val) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }

    return head;
}

