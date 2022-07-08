#include <iostream>

using namespace std;

// 判断单链表中是否有环

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    // 判断单链表中是否有环
    // 快慢指针法
    ListNode *slow(head), *fast(head);

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }

    return false;
}

