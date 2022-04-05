#include <iostream>
#include <vector>

using namespace std;

// 使用递归对数列求和

int fsum(vector<int>::const_iterator& bi, vector<int>::const_iterator& ei) {
    int sum = 0;
    if (bi == ei) {
        return 0;
    }
    else {
        sum = *bi + fsum(++ bi, ei);
        return sum;
    }
}

int main() {
    vector<int> vi{2, 3, 4, 1, 6, 7, 8, 0, 9, 4, 3, 5, 6, 8};
    auto bi = vi.cbegin(), ei = vi.cend();
    cout << fsum(bi, ei) << endl;

    return 0;
}
