#include <iostream>

using std::cout;
using std::endl;

// �������ʵ�εľ���ֵ

int par_abs(int val) {
    int abs_val = 0;
    (val < 0) ? abs_val = -val : abs_val = val;
    return abs_val;
}


int main() {
    int num = 8;
    cout << par_abs(num) << endl;
    cout << par_abs(-num) << endl;
    return 0;
}
