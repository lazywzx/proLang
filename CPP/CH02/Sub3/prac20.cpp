#include<iostream>

// 指针所指对象的运算
int main()
{
    int i = 42;
    int *pl = &i;
    *pl = *pl * *pl;

    std::cout << i << std::endl;

    return 0;
}
