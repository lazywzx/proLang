#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

// ��ָ�뽫����Ԫ����Ϊ0

int iarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    cout << "���飺" << endl;
    for (auto &n : iarr) {
        cout << n << "\t";
    }
    cout << endl;

    for (int *pb = begin(iarr), *pe = end(iarr); pb != pe; ++ pb) {
        *pb = 0;
    }

    cout << "Ԫ����Ϊ0" << endl;
    for (auto &n : iarr) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
