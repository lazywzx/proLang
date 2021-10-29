#include<iostream>

// 将50到100的整数相加
int main()
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    
    std::cout << "The sum of 50 to 100 is " 
              << sum << std::endl;
    
    return 0;
}
