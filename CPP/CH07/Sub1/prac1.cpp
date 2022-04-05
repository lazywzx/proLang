#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// �Զ���Sales_data�࣬ʵ���������°汾

struct Sales_data {
    string isbn = "";
    unsigned int count = 0;
    double sale = 0;
};

int main() {
    Sales_data total;
    double price = 0;

    cout << "�����¼��isbn count price" << endl;
    if (cin >> total.isbn >> total.count >> price) {
        total.sale = total.count * price;
        Sales_data trans;
        while (cin >> trans.isbn >> trans.count >> price) {
            trans.sale = trans.count * price;
            if (total.isbn == trans.isbn) {
                total.sale += trans.sale;
                total.count += trans.count;
            }
            else {
                cout << "isbn: " << total.isbn << "\tcount: " << total.count
                     << "\tsale: " << total.sale << endl;
                total = trans;
            }
        }
        cout << "isbn: " << total.isbn << "\tcount: " << total.count
             << "\tsale: " << total.sale << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
