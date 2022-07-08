#include <iostream>
#include "test_list.h"

using namespace std;
/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true ；否则，返回 false 。
进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

/*
bool isPalindrome(ListNode* head) {
    // 原地、一趟，判断是否为回文链表
    // 对链表后半部分翻转，翻转后的后半部分应与前半部分完全一致
    if (head->next == nullptr) {
        return true;
    }

    // 寻找中间节点的方法：1、统计链表长度；2、快慢指针法
    // 统计链表长度
    int sz(2);
    auto pfront(head->next->next);  // 由题目知，运行到此处说明至少有两个节点
    while (pfront != nullptr) {
        ++ sz;
        pfront = pfront->next;
    }

    // 找到左右子链表的结束和开始位置
    int left_end(0), right_begin(0);
    if (sz % 2) {
        // 奇数
        left_end = sz / 2;
        right_begin = left_end + 1;
    }
    else {
        // 偶数
        right_begin = sz / 2;
        left_end = right_begin;
    }

    // 找到右子链表的开始节点
    pfront = head;
    while (right_begin) {
        pfront = pfront->next;
        -- right_begin;
    }

    // 翻转右子链表，pfront作为头节点
    auto p(pfront);
    while (p->next != nullptr) {
        auto pnn(p->next->next);
        p->next->next = pfront;   // 当前节点指向第一个节点
        pfront = p->next;         // 头节点更新为当前一个节点
        p->next = pnn;          // 当前节点前一个节点指向当前节点后一个节点
    }

    // 判断回文，即左右子链表相等
    while (left_end) {
        if (head->val != pfront->val) {
            return false;
        }

        head = head->next;
        pfront = pfront->next;
        -- left_end;
    }

    return true;
}
*/


bool isPalindrome(ListNode* head) {
    // 原地、一趟，判断是否为回文链表
    // 对链表后半部分翻转，翻转后的后半部分应与前半部分完全一致
    if (head->next == nullptr) {
        return true;
    }

    // 寻找中间节点的方法：1、统计链表长度；2、快慢指针法
    auto fast(head->next), slow(head);
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;

    // 奇数链表：slow指向中间右边一个节点；偶数链表：slow指向后半链表的开始节点
    // 翻转右子链表，slow作为头节点
    auto p(slow);
    while (p->next != nullptr) {
        auto pnn(p->next->next);
        p->next->next = slow;   // 当前节点指向第一个节点
        slow = p->next;         // 头节点更新为当前一个节点
        p->next = pnn;          // 当前节点前一个节点指向当前节点后一个节点
    }

    // 判断回文，即左右子链表相等
    while (slow != nullptr) {
        if (head->val != slow->val) {
            return false;
        }

        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main() {
    auto head(create_list());   // 在test_list.h中定义链表
    cout << isPalindrome(head) << endl;

    return 0;
}
