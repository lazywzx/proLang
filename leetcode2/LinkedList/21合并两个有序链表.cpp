/*
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // 合并两升序链表，保持升序
    // 任何一个链表为空，返回另一个即可
    if (list1 == nullptr) {
        return list2;
    }
    else if (list2 == nullptr) {
        return list1;
    }

    // 两链表都不为空
    auto head(list1), p(list1);
    if (list1->val > list2->val) {
        // 初始化
        head = list2;
        p = list2;
        list2 = list2->next;
    }
    else {
        list1 = list1->next;
    }

    // 合并
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            p->next = list1;
            p = list1;
            list1 = list1->next;
        }
        else {
            p->next = list2;
            p = list2;
            list2 = list2->next;
        }
    }

    // 当某个链表到底时
    (list1 == nullptr) ? p->next = list2 : p->next = list1;

    return head;
}
