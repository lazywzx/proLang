#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

class MyLinkedList {
    public:
        // 自定义数据结构
        struct ListNode {
            int val;
            ListNode *prev, *next;
            ListNode() : val(0), prev(nullptr), next(nullptr) {}
            ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
            ListNode(int x, ListNode* prev, ListNode *next) : val(x), prev(prev), next(next) {}
        };

        // 数据成员：空链表
        ListNode* head;

        // 构造函数
        MyLinkedList() {
            head = nullptr;
        }

        // 成员函数
        int get(int index) {
            // 找到第index个节点
            auto p(head);
            while (p != nullptr && index > 0) {
                p = p->next;
                -- index;
            }

            if (p != nullptr) {
                return p->val;
            }
            
            return -1;
        }

        void addAtHead(int val) {
            // 在第一个元素前添加节点
            ListNode* node = new ListNode;
            node->val = val;
            if (head == nullptr) {
                head = node;
            }
            else {
                node->next = head;
                head->prev = node;
                head = node;
            }
        }

        void addAtTail(int val) {
            // 在尾部添加节点
            ListNode* node = new ListNode;
            node->val = val;
            if (head == nullptr) {
                head = node;
            }
            else {
                auto p(head);
                while (p->next != nullptr) {
                    p = p->next;
                }
                p->next = node;
                node->prev = p;
            }
        }

        void addAtIndex(int index, int val) {
            // 在第index个节点前插入节点
            if (index <= 0) {
                addAtHead(val);
            }
            else if (head != nullptr) {
                auto p(head);
                while (p != nullptr && index) {
                    p = p->next;
                    -- index;
                }

                if (p != nullptr) {
                    ListNode* node = new ListNode;
                    node->val = val;
                    node->next = p;
                    p->prev->next = node;
                    node->prev = p->prev;
                    p->prev = node;
                }
                else if (index == 0) {
                    // 在尾部插入节点
                    addAtTail(val);
                }
            }
        }

        void deleteAtIndex(int index) {
            // 删除第index个节点
            if (index == 0) {
                // 删除头节点
                head = head->next;
                if (head != nullptr) {
                    // 多于一个节点
                    head->prev = nullptr;
                }
            }
            else if (index > 0) {
                auto p(head);
                while (p != nullptr && index) {
                    p = p->next;
                    -- index;
                }

                if (p != nullptr) {
                    if (p->next == nullptr) {
                        // 删除尾节点
                        p->prev->next = nullptr;
                        p->prev = nullptr;
                    }
                    else {
                        p->next->prev = p->prev;
                        p->prev->next = p->next;
                    }
                }
            }
        }
};

#endif
