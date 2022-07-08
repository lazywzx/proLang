#include <iostream>
#include "test_list.h"

using namespace std;

/*
给你两个 非空 的链表，表示两个非负的整数。
它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 相加表示两个整数的链表
    ListNode* head = new ListNode;  // 第一个节点作为虚拟节点，最后的头节点从第二个开始
    auto p(head);
    int sump(0), carry(0);

    // 重叠部分相加
    while (l1 || l2) {
        sump = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sump / 10;

        p->next = new ListNode;     // 当前运算结果存在当前创建的节点中
        p = p->next;
        p->val = sump % 10;
        
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    // 判断最后的进位
    if (carry) {
        p->next = new ListNode(1);
    }

    return head->next;
}

int main() {
    auto l1(create_list1()), l2(create_list2());
    auto res(addTwoNumbers(l1, l2));

    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
