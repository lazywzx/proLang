#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ʹ�������������������2

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5};
    for (auto &i : ivec) {
        (i % 2 != 0) ? i *= 2 : i;
    }
    for (auto &i : ivec) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
