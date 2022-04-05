#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

// 使用数组初始化一个容器，将容器拷贝给数组
int iarr1[] = {1, 2, 3, 4, 5};
vector<int> ivec(begin(iarr1), end(iarr1));
int iarr2[5] = {};

int main() {
    for (auto &i : iarr1) {
        cout << i << "\t";
    }
    cout << endl;

    for (auto &v : ivec) {
        cout << v << "\t";
    }
    cout << endl;

    for (int i = 0; i < 5; ++ i) {
        iarr2[i] = ivec[i];
    }
    /*
    int *p = begin(iarr2);
    for (auto it = ivec.cbegin(); it != ivec.cend() && p != end(iarr2); ++ it, ++ p) {
        *p = *it;
    }
    */

    for (auto &i : iarr2) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
