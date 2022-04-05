#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 后置运算符重写程序

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix ++, cnt --) {
        ivec[ix] = cnt;
    }

    /*
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ ix, -- cnt) {
        ivec[ix] = cnt;
    }
    */

    for (auto &i : ivec) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
