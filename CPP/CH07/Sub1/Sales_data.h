#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;

// Sales_data��
struct Sales_data {
    /* ���Ա */
    string bookNo = "";     // ISBN���
    unsigned int units_sold = 0;    // ����
    double revenue = 0.0;   // �����۶�

    /* ��Ա���� */
    string isbn() const {
        // ����ISBN
        return bookNo;
    }

    Sales_data& combine(const Sales_data& trans) {
        // �ϲ���������ۼ�¼
        units_sold += trans.units_sold;
        revenue += trans.revenue;

        return *this;
    }

    double avg_price() const {
        // ���ؾ���
        if (units_sold) {
            return revenue / units_sold;
        }
        else {
            return 0;
        }
    }

    /* ���캯�� */
    Sales_data() = default;
    Sales_data(const string& s): bookNo(s) {}
    // Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(istream& is) {
        double price = 0;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
    }
    Sales_data(const string& s, unsigned n, double p) {
        // ��ʾ��ʼ����Ա
        bookNo = s;
        units_sold = n;
        revenue = p * n;
    }
    

};

// �ǳ�Ա����
istream& read(istream& is, Sales_data& item) {
    // ��ȡ��¼
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;

    return is;
}

ostream& print(ostream& os, const Sales_data& item) {
    // �����¼
    os << "isbn: " << item.isbn() << "\tunits_sold: " << item.units_sold
        << "\trevenue: " << item.revenue << "\tavg_price: " << item.avg_price();
    
    return os;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
    // ��¼���
    Sales_data sum = item1;
    sum.combine(item2);

    return sum;
}

#endif
