#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ����vector��Ԫ����ָ������ָ�룬�ĸ������ֱ�ִ�мӼ��˳�

int fadd(int a, int b) {
    return a + b;
}

int fsub(int a, int b) {
    return a - b;
}

int fmul(int a, int b) {
    return a * b;
}

int fdiv(int a, int b) {
    return a / b;
}

typedef int (*pf)(int, int);
vector<pf> pv = {fadd, fsub, fmul, fdiv};

int main() {
    cout << "����Ԫ��ָ�������ֱ�ִ�мӼ��˳�" << endl;

    int a = 5, b = 6;
    for (auto &f : pv) {
        cout << f(a, b) << "\t";
    }
    cout << endl;

    return 0;
}
