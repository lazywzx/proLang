#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 读入整数，遇到42停止

int main() {
    int val = 0;
    cout << "输入一组整数" << endl;
    while (cin >> val && val != 42) {
        cout << val << endl;
    }

    return 0;
}
