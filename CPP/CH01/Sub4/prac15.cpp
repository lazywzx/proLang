#include<iostream>

// 包含“再探编译”中的常见错误

// /* 语法错误 syntax error */
// int main(    // 漏掉main的参数列表
// {
//     return 0;
// }

// int main()
// {
//     std::cout << "Read each file." << std::endl:    // endl之后使用了冒号:
//     std::cout << Update master. << std::endl;   // 字符串两侧漏掉引号""
//     std::cout << "Write new master." std::endl; // 漏掉输出运算符::
//     return 0    // 语句漏掉分号;
// }

// /* 类型错误 type error */
// int main()
// {
//     int number = "string";  // 传递了错误的数据类型
//     return 0;
// }

// /* 声明错误 declaration error */
// int main()
// {
//     int v1 = 3, v2 = 5;
//     std::cout << v << " " << v2 << std::endl;   // 标识符拼写错误
//     cout << v1 + v1 << std::endl;   // 漏掉命名空间声明
//     return 0;
// }
