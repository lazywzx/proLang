#include <iostream>

using namespace std;

/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 
如果链表无环，则返回 null。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    // 返回链表开始入环的结点，如果无环返回null
    // 快慢指针法
    ListNode *slow(head), *fast(head);

    while (fast != NULL && fast->next != NULL) {
        // 判断是否有环
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            /*
            通过推导发现：
            当fast与slow相遇时，slow到入口结点的前向距离l、head到入口结点的距离x
            满足关系：x = l + ks, k>=0, s为环路周长
            因此，从slow和head同时出发，相同速度前进，一定会在入口处相遇
            */
           ListNode* p(head);
           while (p != slow) {
               slow = slow->next;
               p = p->next;
           }

           return p;
        }
    }

    return NULL;
}
