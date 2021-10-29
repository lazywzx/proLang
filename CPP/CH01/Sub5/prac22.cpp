#include<iostream>
#include "Sales_item.hpp"

// 读入多条具有相同ISBN的记录，打印他们的和
int main()
{
    std::cout << "读入多条具有相同ISBN的记录，输出他们的和：" << std::endl;

    Sales_item book, sum;
    if (std::cin >> book)   // 保证至少有一组有效输入
    {
        sum = book;
        while (std::cin >> book)
        {
            sum += book;
        }
        std::cout << sum << std::endl;
    }
    else
    {
        std::cerr << "无有效输入！" << std::endl;
    }

    return 0;  
}
