#include<iostream>

// 赋值会产生引用
int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;

    std::cout << a << "\t" << b << "\t" << c << "\t" << d << std::endl;

    return 0;
}
