#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 声明vector，元素是指向函数的指针，四个函数分别执行加减乘除

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
    cout << "容器元素指向函数，分别执行加减乘除" << endl;

    int a = 5, b = 6;
    for (auto &f : pv) {
        cout << f(a, b) << "\t";
    }
    cout << endl;

    return 0;
}
