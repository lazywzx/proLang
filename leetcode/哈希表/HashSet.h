#ifndef HASHSET_H_
#define HASHSET_H_

/* 
// 链表节点
struct ListNode2 {
    int val;
    ListNode2 *next;
    ListNode2() : val(0), next(nullptr) {}
    ListNode2(int x) : val(x), next(nullptr) {}
    ListNode2(int x, ListNode2 *next) : val(x), next(next) {}
};


// 哈希集合
class MyHashSet {
    // 数组加链表实现
    // 数据成员
    // 存储101个链表的数组，每个链表能表示10^4个数据，总共能表示0~101*10^4-1
    ListNode2* hashset[101] = {};

    public:
        MyHashSet() {
            // 默认构造，什么都不做
        }
        
        void add(int key) {
            // 添加key到哈希表
            auto head(hashset[key / 10000]);
            if (head == nullptr) {
                hashset[key / 10000] = new ListNode2(key);
            }
            else {
                while (head != nullptr && head->val != key) {
                    head = head->next;
                }
                if (head == nullptr) {
                    // 将key加入到头节点
                    hashset[key / 10000] = new ListNode2(key, hashset[key / 10000]);
                }
            }
        }
        
        void remove(int key) {
            // 移除key
            auto head(hashset[key / 10000]);
            if (head != nullptr) {
                if (head->val == key) {
                    // 删除头节点
                    hashset[key / 10000] = head->next;
                }
                else {
                    while (head->next != nullptr) {
                        if (head->next->val == key) {
                            head->next = head->next->next;
                            break;
                        }
                        else {
                            head = head->next;
                        }
                    }
                }
            }
        }
        
        bool contains(int key) {
            // 查找key
            auto head(hashset[key / 10000]);
            while (head != nullptr) {
                if (head->val == key) {
                    return true;
                }
                head = head->next;
            }

            return false;
        }
};
*/


class MyHashSet {
    // 纯数组实现
    // 数据成员
    // 存储101个链表的数组，每个链表能表示10^4个数据，总共能表示0~101*10^4-1
    bool hashset[1000001] = {false};

    public:
        MyHashSet() {
            // 默认构造，什么都不做
        }
        
        void add(int key) {
            // 添加key到哈希表
            if (!hashset[key]) {
                hashset[key] = true;
            }
        }
        
        void remove(int key) {
            // 移除key
            if (hashset[key]) {
                hashset[key] = false;
            }
        }
        
        bool contains(int key) {
            // 查找key
            if (hashset[key]) {
                return true;
            }
            return false;
        }
};

#endif
