#include <iostream>

using std::cout;
using std::endl;

// ��׳�

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val --;
    }

    return ret;
}


int main() {
    int num = 5;
    int res = fact(num);
    cout << num << "�Ľ׳�Ϊ" << res << endl;

    return 0;
}
