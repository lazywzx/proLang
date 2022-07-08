#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <cstring>

using namespace std;

// 哈希映射
// 实现1：数组加链表，略
// 实现2：纯数组


class MyHashMap {
    int hashmap[1000001];
    public:
        MyHashMap() {
            memset(hashmap, -1, sizeof(hashmap));
        }
        
        void put(int key, int value) {
            // 添加
            hashmap[key] = value;
        }
        
        int get(int key) {
            return hashmap[key];
        }
        
        void remove(int key) {
            hashmap[key] = -1;
        }
};

#endif
