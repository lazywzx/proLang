#include<iostream>
#include "Sales_item.hpp"

// 读取多条销售记录，统计每个ISBN有多少条销售记录
int main()
{
    Sales_item currBook, book;
    std::cout << "输入多条销售记录（相同ISBN的销售记录应聚在一起）：" << std::endl;

    int cnt = 1;
    if (std::cin >> currBook)
    {
        while (std::cin >> book)
        {
            if (currBook.isbn() == book.isbn())
            {
                ++cnt;
            }
            else
            {
                std::cout << currBook.isbn() << " occurs " << cnt << " times." << std::endl;
                cnt = 1;
                currBook = book;
            }
        }
    }
    
    std::cout << currBook.isbn() << " occurs " << cnt << " times." << std::endl;

    return 0;
}
