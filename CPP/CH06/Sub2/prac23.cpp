#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

// �����β�

void print1(int num, const int arr[], size_t size) {
    // ��ʽ���������С
    cout << num << endl;
    for (size_t i = 0; i != size; ++ i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void print2(int num, const int* beg, const int* end) {
    // ʹ��ָ��
    cout << num << endl;
    for (; beg != end; ++ beg) {
        cout << *beg << "\t";
    }
    cout << endl;
}

void print3(int num, const int (&arr)[2]) {
    // ʹ�������β�
    cout << num << endl;
    for (auto &val : arr) {
        cout << val << "\t";
    }
    cout << endl;
}


int main() {
    int i = 0, j[2] = {0, 1};
    print1(i, j, 2);
    print2(i, begin(j), end(j));
    print3(i, j);

    return 0;
}
