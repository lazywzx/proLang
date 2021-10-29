#include<iostream>

// auto类型说明符
int main()
{
    int i = 0, &r = i;
    auto a = r; // a是一个整数

    // auto 一般会忽略顶层auto，而保留底层auto
    const int ci = i, &cr = ci;
    auto b = ci;    // b是一个整数
    auto c = cr;    // c是一个整数
    auto d = &i;    // d是一个整型指针
    auto e = &ci;   // e是一个指向整型常量的指针，对常量对象取地址是一种底层const

    // 希望推断出顶层const则需要明确指出
    const auto f = ci;  // f是const int

    auto &g = ci;   // 设置auto类型的引用时，顶层const保留

    std::cout << "赋值前：" << std::endl;
    std::cout << a << "\t" << b << "\t" << c << "\t"
              << d << "\t" << e << "\t" << g << std::endl;
    
    a = 42; b = 42; c = 42;
    // d = 42; e = 42; g = 42;

    std::cout << "赋值后：" << std::endl;
    std::cout << a << "\t" << b << "\t" << c << "\t"
              << d << "\t" << e << "\t" << g << std::endl;
    
    return 0;
}
