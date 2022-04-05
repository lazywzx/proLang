#include <iostream>
#include "Sales_data.h"
#include <string>
#include <vector>

using std::cin;

// 使用委托构造函数

int main() {
    Sales_data item1;
    Sales_data item2("x-2333");
    Sales_data item3(cin);

    return 0;
}
