#include <iostream>

using std::cout;
using std::endl;

// 使用引用传参

void reset(int &i) {
    i = 0;
}

int main() {
    int a = 10;
    reset(a);
    cout << a << endl;

    return 0;
}
