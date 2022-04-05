#include <iostream>

using std::cout;
using std::endl;

// 返回int数组的引用

int odd[5] = {1, 3, 5, 7, 9};
int even[5] = {0, 2, 4, 6, 8};

decltype(odd) &arrRef(int i) {
    int (&oddr)[5] = odd;
    int (&evenr)[5] = even;
    return (i % 2) ? oddr: evenr;
}

int main() {
    for (auto &n : arrRef(6)) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
