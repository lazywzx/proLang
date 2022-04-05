#include <iostream>

using std::cout;
using std::endl;

// 同时使用形参，局部变量，局部静态变量

int func(int val) {
    int local_val = val * 2;
    static int s_l_val =0;

    s_l_val += (local_val + 1);

    return s_l_val;
}

int main() {
    int num = 5;
    int res = 0;
    for (int i = 0; i != 3; ++ i) {
        res = func(num);
    }
    cout << res << endl;

    return 0;
}
