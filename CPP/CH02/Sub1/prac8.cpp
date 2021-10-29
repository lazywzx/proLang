#include<iostream>

// 输出2M转到新的一行；输出2制表符M转到新的一行
int main()
{
    std::cout << "2\115\n" << std::endl;
    std::cout << "2\t\115\n" << std::endl;

    std::cout << "\145\t\012" << std::endl;
    return 0;
}
