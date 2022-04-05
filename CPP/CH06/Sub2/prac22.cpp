#include <iostream>

using std::cout;
using std::endl;

// 使用指针的引用int* &p交换指针

void exchange_p(int* &p1, int* &p2) {
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main() {
    int v1 = 1, v2 = 2;
    int* p1 = &v1;
    int* p2 = &v2;
    cout << *p1 << "\t" << *p2 << endl;

    exchange_p(p1, p2);
    cout << *p1 << "\t" << *p2 << endl;

    return 0;
}
