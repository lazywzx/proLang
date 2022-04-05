#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

using std::string;
struct Sales_data {
    string isbn = "";
    unsigned int count = 0;
    double sale = 0;
    unsigned int num = 0;   // 该书的销售纪录数
};

#endif
