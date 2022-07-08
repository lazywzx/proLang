/*
给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。
第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* oddEvenList(ListNode* head) {
    // 原地、一趟遍历，将链表中奇偶位置节点保持原顺序集中，奇在前
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        // 0个或1个或2个节点，直接返回
        return head;
    }

    auto po(head), pe(head->next);
    auto pe_first(pe);
    // 奇偶合并
    while (po->next != nullptr && pe->next != nullptr) {
        po->next = pe->next;    // 连接奇数节点
        po = po->next;
        pe->next = po->next;    // 连接偶数节点
        pe = pe->next;
    }

    po->next = pe_first;    // 将偶数节点子链表连接到奇数子链表
    
    return head;
}
