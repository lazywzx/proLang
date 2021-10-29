#include<iostream>

// 使用--运算符，按照递减顺序依次打印10到0之间的整数
int main()
{
    int val = 10;

    while (val >= 0)
    {
        std::cout << val << " ";
        --val;
    }

    std::cout << std::endl;

    return 0;
}
