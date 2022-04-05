#include <iostream>
#include <vector>

using namespace std;

// 使用递归计算数列元素数

int fsize(vector<int>::const_iterator& bi, vector<int>::const_iterator& ei) {
    int size = 0;
    if (bi == ei) {
        return 0;
    }
    else {
        size = 1 + fsize(++ bi, ei);
        return size;
    }
}

int main() {
    vector<int> vi{2, 3, 4, 1, 6, 7, 8, 0, 9, 4, 3, 5, 6, 8};
    auto bi = vi.cbegin(), ei = vi.cend();
    cout << fsize(bi, ei) << endl;

    return 0;
}
