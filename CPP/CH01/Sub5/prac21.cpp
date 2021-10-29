#include<iostream>
#include "Sales_item.hpp"

// 读取两个相同ISBN的对象，输出他们的和
int main()
{
    Sales_item book1, book2;
    
    std::cout << "输入两条相同ISBN的交易记录，打印他们的和：" << std::endl;
    std::cin >> book1 >> book2; //读取一对交易记录
    std::cout << book1 + book2 << std::endl;    // 打印他们的和

    return 0;
}
