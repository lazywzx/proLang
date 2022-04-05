#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// 使用istream构造函数重写交易处理程序

int main() {
    cout << "输入交易记录，格式：bookNo units_sold price" << endl;
    Sales_data total(cin);
    if (total.units_sold != 0) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
