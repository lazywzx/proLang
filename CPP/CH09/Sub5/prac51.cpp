#include <iostream>
#include "Date2.h"

using namespace std;

// 测试Date类

int main() {
    cout << "默认构造" << endl;
    Date2 d1;
    d1.print(cout) << endl;

    cout << "March 13, 2022" << endl;
    Date2 d2("March 13, 2022");
    d2.print(cout) << endl;

    cout << "13/3/2022" << endl;
    Date2 d3("13/3/2022");
    d3.print(cout) << endl;

    cout << "Mar 13 2022" << endl;
    Date2 d4("Mar 13 2022");
    d4.print(cout) << endl;

    return 0;
}