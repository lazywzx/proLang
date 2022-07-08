/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
ListNode* rotateRight(ListNode* head, int k) {
    // 向右旋转链表k次
    if (head == nullptr) {
        return head;
    }

    // 计算实际需要旋转的次数
    int sz(0);
    auto p(head);
    while (p != nullptr) {
        ++ sz;
        p = p->next;
    }

    int rot(k % sz);    // 右旋次数
    if (rot > sz - rot) {
        rot = sz - rot; // 左旋次数
        // 左旋rot次
        int tmp_head(0);
        while (rot) {
            // 单次旋转
            p = head;
            tmp_head = p->val;
            while (p->next != nullptr) {
                p->val = p->next->val;
                p = p->next;
            }
            p->val = tmp_head;
            -- rot;
        }

        return head;
    }
    else {
        // 右旋rot次
        int tmp_prev(0), tmp_curr(0);
        while (rot) {
            // 单次旋转
            p = head;
            tmp_prev = p->val;
            while (p->next != nullptr) {
                tmp_curr = p->next->val;
                p->next->val = tmp_prev;
                tmp_prev = tmp_curr;
                p = p->next;
            }
            head->val = tmp_prev;
            -- rot;
        }

        return head;
    }
}
*/


ListNode* rotateRight(ListNode* head, int k) {
    // 向右旋转链表k次
    // 不要真的旋转，只要把头节点移动到正确位置即可
    // 先成环，再在正确位置断开
    if (head == nullptr) {
        return head;
    }

    // 计算实际需要旋转次数
    int sz(1);
    auto p(head);
    while (p->next != nullptr) {
        ++ sz;
        p = p->next;
    }

    sz = sz - k % sz - 1;    // 实际旋转次数
    // 成环
    p->next = head;
    // 旋转
    while (sz) {
        head = head->next;
        -- sz;
    }

    // 开环
    p = head->next;
    head->next = nullptr;

    return p;
}
