#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

// 用指针将数组元素置为0

int iarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    cout << "数组：" << endl;
    for (auto &n : iarr) {
        cout << n << "\t";
    }
    cout << endl;

    for (int *pb = begin(iarr), *pe = end(iarr); pb != pe; ++ pb) {
        *pb = 0;
    }

    cout << "元素置为0" << endl;
    for (auto &n : iarr) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
