#include<iostream>
#include "Sales_item.hpp"

// 读取一组书籍销售记录，并打印到标准输出上
int main()
{
    Sales_item book;
    std::cout << "读入ISBN号、售出的册数以及销售价格：" << std::endl;
    std::cin >> book;

    std::cout << "打印ISBN号、售出的册数、总销售额和平均价格：" << std::endl;
    std::cout << book << std::endl;

    return 0;
}
