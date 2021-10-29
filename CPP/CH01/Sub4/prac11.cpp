#include<iostream>

// 提示用户输入两个整数，打印两整数之间的所有整数
int main()
{
    std::cout << "Enter two numbers(min, max): " << std::endl;

    int minVal = 0, maxVal = 0;
    std::cin >> minVal >> maxVal;

    while (minVal <= maxVal)
    {
        std::cout << minVal << " ";
        ++minVal;
    }
    
    std::cout << std::endl;

    return 0;
}
