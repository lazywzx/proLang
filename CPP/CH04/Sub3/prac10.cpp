#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// ��������������42ֹͣ

int main() {
    int val = 0;
    cout << "����һ������" << endl;
    while (cin >> val && val != 42) {
        cout << val << endl;
    }

    return 0;
}
