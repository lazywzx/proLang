#include <iostream>

using std::cout;
using std::endl;

// 使用引用形参交换两整数值

void exchange_val(int &p1, int &p2) {
    int tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main() {
    int val1 = 10, val2 = 15;
    cout << val1 << "\t" << val2 << endl;

    exchange_val(val1, val2);
    cout << val1 << "\t" <<  val2 << endl;

    return 0;
}
