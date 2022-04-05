#include <iostream>

using std::cout;
using std::endl;

// 输出函数调用次数

int func(void) {
    static int cnt = 0;
    return cnt ++;
}

int main() {
    for (int i = 0; i != 10; ++ i) {
        cout << func() << endl;
    }

    return 0;
}
