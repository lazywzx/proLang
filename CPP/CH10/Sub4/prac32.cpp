#include <iostream>
#include "Sales_data.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

// 使用sort、compareIsbn、find、accumulate重写书店程序
// 每条交易记录存入vector，排序后再求和

/* 比较ISBN */
bool compareIsbn(Sales_data& s1, Sales_data& s2) {
    return s1.isbn() < s2.isbn();
}

/* 读取记录，存入容器 */
istream& read_items(istream& is, vector<Sales_data>& v) {
    Sales_data trans;
    while (read(is, trans)) {
        v.push_back(trans);
    }
    is.clear();
    return is;
}

/* 按isbn排序记录 */
void sort_items(vector<Sales_data>& v) {
    sort(v.begin(), v.end(), compareIsbn);
}

/* 求和并输出 */
ostream& print_items(ostream& os, vector<Sales_data>& v) {
    Sales_data total;
    vector<double> rev;
    vector<unsigned> sold;
    vector<string> no;
    for (auto& s : v) {
        rev.push_back(s.revenue);
        sold.push_back(s.units_sold);
        no.push_back(s.isbn());
    }

    auto rb = rev.cbegin(), re = rev.cend();
    auto sb = sold.cbegin(), se = sold.cend();
    auto begin_iter = v.cbegin(), end_iter = v.cend();

    while (begin_iter != v.cend()) {
        end_iter = find_if(begin_iter, v.cend(), [begin_iter](const Sales_data& i) -> bool {return (i.isbn() != begin_iter->isbn());});
        se = sb + (end_iter - begin_iter);
        re = rb + (end_iter - begin_iter);

        total.revenue = accumulate(rb, re, 0);
        total.units_sold = accumulate(sb, se, 0);
        total.bookNo = begin_iter->isbn();

        print(os, total) << endl;
        begin_iter = end_iter;

        sb = se;
        rb = re;
    }

    return os;
}

int main() {
    cout << "输入交易记录" << endl;
    vector<Sales_data> items;
    if (read_items(cin, items)) {
        sort_items(items);
        print_items(cout, items);
    }
    else {
        cerr << "Error data?!" << endl;
    }

    return 0;
}
