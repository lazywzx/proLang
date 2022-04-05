#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// ʹ��istream���캯����д���״������

int main() {
    cout << "���뽻�׼�¼����ʽ��bookNo units_sold price" << endl;
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
