#include <iostream>

using std::cout;
using std::endl;

// 比较整数与指针所指整数的大小

int compare(int val1, int *pval2) {
    return ((val1 > *pval2) ? val1 : *pval2);
}

int main() {
    int val1 = 8, val2 = 6;
    cout << "较大的数是" << compare(val1, &val2) << endl;

    return 0;
}
