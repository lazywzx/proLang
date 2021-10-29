#include<iostream>

// 使用for循环，从-100累加到100
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
    {
        sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}
