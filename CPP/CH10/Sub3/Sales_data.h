#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <istream>
#include <ostream>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class Sales_data;

istream& read(istream& is, Sales_data& item);

// Sales_data类
class Sales_data {
    /* 友元声明 */
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

    /* 私有 */
    private:
        /* 类成员 */
        string bookNo = "";     // ISBN编号
        unsigned int units_sold = 0;    // 销量
        double revenue = 0.0;   // 总销售额
    /* 公有 */
    public:
        /* 成员函数 */
        string isbn() const {
            // 返回ISBN
            return bookNo;
        }

        Sales_data& combine(const Sales_data& trans) {
            // 合并该书的销售记录
            units_sold += trans.units_sold;
            revenue += trans.revenue;

            return *this;
        }

        inline double avg_price() const {
            // 返回均价，显示内联
            return units_sold ? revenue / units_sold : 0;
        }

        /* 构造函数 */
        Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
        /* 委托构造函数 */
        Sales_data(): Sales_data("", 0, 0) {}
        Sales_data(const string& s): Sales_data(s, 0, 0) {}
        Sales_data(istream& is): Sales_data() {
            read(is, *this);
        }
        /* 
        Sales_data(const string& s, unsigned n, double p) {
            // 显示初始化成员
            bookNo = s;
            units_sold = n;
            revenue = p * n;
        }
        */

};

// 非成员函数
istream& read(istream& is, Sales_data& item) {
    // 读取记录
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;

    return is;
}

ostream& print(ostream& os, const Sales_data& item) {
    // 输出记录
    os << "isbn: " << item.isbn() << "\tunits_sold: " << item.units_sold
        << "\trevenue: " << item.revenue << "\tavg_price: " << item.avg_price();
    
    return os;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
    // 记录相加
    Sales_data sum = item1;
    sum.combine(item2);

    return sum;
}

#endif
