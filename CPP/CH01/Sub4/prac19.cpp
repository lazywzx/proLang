#include<iostream>

// 递减输出一个范围的整数，能够处理第一个数小于第二个数的情况
int main()
{
    std::cout << "Enter two numbers, and I will print all numbers between them."
              << std::endl;
    
    int val1 = 0, val2 = 0;
    std::cin >> val1 >> val2;

    if (val1 < val2)
    {
        while (val2 >= val1)
        {
            std::cout << val2 << " ";
            --val2;
        }
    }
    else
    {
        while (val1 >= val2)
        {
            std::cout << val1 << " ";
            --val1;
        }
    }
    
    return 0;
}
