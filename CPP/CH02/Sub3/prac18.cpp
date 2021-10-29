#include<iostream>

// 改变指针的值、改变指针所指对象的值
int main()
{
    int value = 6, *vp = &value;
    std::cout << "value: " << value
              << "\tpointer: " << vp
              << "\tpointer to object: " << *vp
              << std::endl;
    
    std::cout << "Change value for pointer: " << std::endl;
    vp = 0; // 指针在这里已经改变
    std::cout << "The new pointer: " << vp << std::endl;

    vp = &value;    // 恢复指针的原地址
    std::cout << "Change value for object: " << std::endl;
    *vp = 8;
    std::cout << "The new object: " << value << std::endl;

    return 0;
}
