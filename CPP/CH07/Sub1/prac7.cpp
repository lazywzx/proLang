#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// ʹ��read()��print()��add()�ǳ�Ա����

int main() {
    Sales_data total;
    double price = 0;
    cout << "����������ۼ�¼��" << endl;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
