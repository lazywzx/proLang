#include <iostream>
#include "double_linked_list.h"

using namespace std;

// 测试双链表

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    auto res = obj->get(1);
    cout << res << endl;

    obj->deleteAtIndex(1);
    res = obj->get(1);
    cout << res << endl;

    return 0;
}
