#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// 使用构造函数

int main() {
    Sales_data bk1, bk2("bookNo"), bk3("bookNo", 6, 6);
    cout << "输入bk4的初始值" << endl;
    Sales_data bk4(cin);

    print(cout, bk1) << endl;
    print(cout, bk2) << endl;
    print(cout, bk3) << endl;
    print(cout, bk4) << endl;

    return 0;
}
