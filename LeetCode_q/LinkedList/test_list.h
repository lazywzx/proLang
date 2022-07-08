#ifndef TEST_LIST_H_
#define TEST_LIST_H_
/*
创建链表，可用于调试其他算法
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 创建空的头节点
ListNode* create_head() {
    ListNode* head = nullptr;
    return head;
}

// 创建节点
ListNode* create_node(int val=0, ListNode* next=nullptr) {
    ListNode* p = new ListNode;
    p->val = val;
    p->next = next;

    return p;
}

// 创建链表
ListNode* create_list1() {
    ListNode* head(create_node(1));
    // 添加其他节点
    ListNode* p(head);
    
    p->next = create_node(2);
    p = p->next;

    p->next = create_node(3);
    p = p->next;

    return head;
}

ListNode* create_list2() {
    ListNode* head(create_node(0));
    // 添加其他节点
    ListNode* p(head);
    
    p->next = create_node(6);
    p = p->next;

    p->next = create_node(2);
    p = p->next;

    return head;
}

#endif
