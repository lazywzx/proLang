#include<iostream>

int main()
{
    std::cout << "Enter two numbers:";
    std::cout << std::endl;
    
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;

    // 不合法，分号代表一条语句结束，<<运算符缺失左侧运算对象
    /*
    std::cout << "The sum of " << v1;
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
    */

   // 修正示例
   std::cout << "The sum of " << v1;
   std::cout << " and " << v2;
   std::cout << " is " << v1 + v2 << std::endl;

    return 0;
}
