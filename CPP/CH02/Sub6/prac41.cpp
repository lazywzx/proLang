#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 改写以前的练习题，使用Sales_data

struct Sales_data {
    string isbn = "";
    unsigned int count = 0;
    double sale = 0;
    unsigned int num = 0;   // 该书的销售纪录数
};

int main()
{
    /* 21
    Sales_data book1, book2;
    double price = 0;

    cout << "输入两条相同ISBN的交易记录，打印他们的和：" << endl;
    cin >> book1.isbn >> book1.count >> price; //读取一条交易记录
    book1.sale = book1.count * price;
    cin >> book2.isbn >> book2.count >> price;
    book2.sale = book2.count * price;

    cout << "isbn: " << book1.isbn << "\tcount: " << book1.count + book2.count
         << "\tsale: " << book1.sale + book2.sale << endl;    // 打印他们的和
    */
    /* 22
    Sales_data total;
    double price = 0;
    cout << "输入多条相同isbn的销售纪录：" << endl;
    if (cin >> total.isbn >> total.count >> price) {
        total.sale = total.count * price;
        Sales_data trans;
        while (cin >> trans.isbn >> trans.count >> price) {
            trans.sale = trans.count * price;
            total.count += trans.count;
            total.sale += trans.sale;
        }
        cout << "isbn: " << total.isbn << "\tcount: " << total.count
             << "\tsale: " << total.sale << endl;
    }
    else {
        std::cerr << "No data?!" << endl;
    }
    */
    /*  23
    Sales_data bk1, bk2, bk3;
    bk1.isbn = "x-2234";
    bk2.isbn = "x-2233";
    bk3.isbn = "x-2231";

    double price = 0;
    string isbn = "";
    int count = 0;

    cout << "输入多条销售记录：" << endl;
    while (cin >> isbn >> count >> price) {
        if (isbn == bk1.isbn) {
            bk1.count += count;
            bk1.sale += count * price;
            ++ bk1.num;
        }
        else if (isbn == bk2.isbn) {
            bk2.count += count;
            bk2.sale += count * price;
            ++ bk2.num;
        }
        else if (isbn == bk3.isbn) {
            bk3.count += count;
            bk3.sale += count * price;
            ++ bk3.num;
        }
        else {
            std::cerr << "We don't have this book, error data!" << endl;
        }
    }

    cout << "isbn: " << bk1.isbn << "\tnum: " << bk1.num << endl;
    cout << "isbn: " << bk2.isbn << "\tnum: " << bk2.num << endl;
    cout << "isbn: " << bk3.isbn << "\tnum: " << bk3.num << endl;
    */
   
    return 0;
}
