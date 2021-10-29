#include<iostream>

// 使用for循环重做prac9~11
int main()
{
    std::cout << "使用for循环累加50到100之间的整数" << std::endl;
    int sum = 0;
    for (int  i = 50; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "The sum of 50 to 100 is " << sum << std::endl;

    std::cout << std::endl;
    std::cout << "使用递减运算符按照递减顺序打印10到0之间的整数" << std::endl;
    for (int i = 10; i >= 0; --i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "提示输入两个整数，打印两数之间整数" << std::endl;
    std::cout << "Enter two numbers(min, max): " << std::endl;
    int minVal = 0, maxVal = 0;
    std::cin >> minVal >> maxVal;
    for (; minVal <= maxVal; ++minVal)
    {
        std::cout << minVal << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
