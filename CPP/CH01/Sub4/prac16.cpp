#include<iostream>

// 读入一组数据并求和

int main()
{
    std::cout << "Enter a list of numbers: " << std::endl;

    int value = 0, sum = 0;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "The sum of input is " << sum << std::endl;

    return 0;
}
