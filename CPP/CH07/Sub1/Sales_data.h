#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;

// Sales_data类
struct Sales_data {
    /* 类成员 */
    string bookNo = "";     // ISBN编号
    unsigned int units_sold = 0;    // 销量
    double revenue = 0.0;   // 总销售额

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

    double avg_price() const {
        // 返回均价
        if (units_sold) {
            return revenue / units_sold;
        }
        else {
            return 0;
        }
    }

    /* 构造函数 */
    Sales_data() = default;
    Sales_data(const string& s): bookNo(s) {}
    // Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(istream& is) {
        double price = 0;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
    }
    Sales_data(const string& s, unsigned n, double p) {
        // 显示初始化成员
        bookNo = s;
        units_sold = n;
        revenue = p * n;
    }
    

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
