#include <iostream>

using std::cout;
using std::endl;

// ����������ô���

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
