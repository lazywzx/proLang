#include <iostream>

using std::cout;
using std::endl;

// �������������ռ�ռ��С

int main() {
    cout << sizeof(bool) << "\t" << sizeof(char) << "\t" << sizeof(wchar_t) << "\t"
         << sizeof(char16_t) << "\t" << sizeof(char32_t) << "\t" << sizeof(short) << "\t"
         << sizeof(int) << "\t" << sizeof(long) << "\t" << sizeof(long long) << "\t"
         << sizeof(float) << "\t" << sizeof(double) << "\t" << sizeof(long double) << "\t"
         << sizeof(void) << endl;
    return 0;
}
