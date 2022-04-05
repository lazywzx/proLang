#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// 使用isbn()和combine()成员函数

int main() {
    Sales_data total;
    double price = 0;
    cout << "输入多条销售记录：" << endl;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                cout << "isbn: " << total.isbn() << "\tunits_sold: " << total.units_sold
                     << "\trevenue: " << total.revenue << endl;
                total = trans;
            }
        }
        cout << "isbn: " << total.isbn() << "\tunits_sold: " << total.units_sold
            << "\trevenue: " << total.revenue << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
