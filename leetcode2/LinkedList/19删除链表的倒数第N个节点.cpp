#include <vector>

using namespace std;

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
要求一趟扫描完成
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 一趟扫描删除倒数第n个节点
    // 存储下每个节点的地址
    auto tmpP(head);
    vector<ListNode*> vLN;
    while (tmpP != nullptr) {
        vLN.push_back(tmpP);
        tmpP = tmpP->next;
    }

    // 正数第几个，存到n中
    n = vLN.size() - n;
    if (n == 0) {
        return head->next;
    }

    vLN[n - 1]->next = vLN[n]->next;
    
    return head;
}
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 一趟扫描删除倒数第n个节点
    // 双指针法
    auto fastP(head), slowP(head);
    // 快慢指针形成一个窗口，宽度为n，当快指针抵达链表尾时，
    // 慢指针正好在要删除节点处前一个节点

    while (n) {
        fastP = fastP->next;
        -- n;
    }

    // 如果删除的是第一个
    if (fastP == nullptr) {
        return head->next;
    }

    while (fastP->next != nullptr) {
        fastP = fastP->next;
        slowP = slowP->next;
    }


    slowP->next = slowP->next->next;

    return head;
}

