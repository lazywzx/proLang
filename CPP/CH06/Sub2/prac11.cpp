#include <iostream>

using std::cout;
using std::endl;

// ʹ�����ô���

void reset(int &i) {
    i = 0;
}

int main() {
    int a = 10;
    reset(a);
    cout << a << endl;

    return 0;
}
