#include <iostream>

using std::cout;
using std::endl;

// �Ƚ�������ָ����ָ�����Ĵ�С

int compare(int val1, int *pval2) {
    return ((val1 > *pval2) ? val1 : *pval2);
}

int main() {
    int val1 = 8, val2 = 6;
    cout << "�ϴ������" << compare(val1, &val2) << endl;

    return 0;
}
