#include <iostream>

using namespace std;

/* 
给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 寻找相交链表的开始相交节点
    // 先遍历两个链表，求出二者长度
    int countA(0), countB(0);
    auto tmpP(headA);
    while (tmpP != NULL) {
        ++ countA;
        tmpP = tmpP->next;
    }

    tmpP = headB;
    while (tmpP != NULL) {
        ++ countB;
        tmpP = tmpP->next;
    }

    // 较长的链表先前进|countA - countB|个节点
    if (countA > countB) {
        countA = countA - countB;
        for (int i(0); i != countA; ++ i) {
            headA = headA->next;
        }
    }
    else {
        countB = countB - countA;
        for (int i(0); i != countB; ++ i) {
            headB = headB->next;
        }
    }

    // 此时两链表的尾部已对齐
    while (headA != headB && headA != NULL) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
