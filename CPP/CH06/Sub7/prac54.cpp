#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ����vector��Ԫ����ָ������ָ��

int func(int, int) {
    cout << "func" << endl;
    return 0;
}

int func2(int, int) {
    cout << "func2" << endl;
    return 0;
}

typedef int (*pf)(int, int);
vector<pf> pv = {func, func2};

int main() {
    cout << pv[1](2, 3) << endl;

    return 0;
}
