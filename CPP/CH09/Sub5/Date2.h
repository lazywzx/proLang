#ifndef DATE2_H
#define DATE2_H

#include <string>
#include <iostream>

using namespace std;

/* Date类 */
class Date2 {
    private:
        unsigned year = 0;
        unsigned month = 0;
        unsigned day = 0;
    
    public:
        /* 构造函数 */
        Date2() = default;
        Date2(const string& s);
        /* 输出日期 */
        ostream& print(ostream& os) {
            os << "年\t月\t日" << endl;
            os << year << "\t" << month << "\t" << day;
            return os;
        }
};

/* 返回月份的数字表示 */
unsigned month_val(const string& m) {
    if (m == "Jan" || m == "January") return 1;
    if (m == "Feb" || m == "February") return 2;
    if (m == "Mar" || m == "March") return 3;
    if (m == "Apr" || m == "April") return 4;
    if (m == "May") return 5;
    if (m == "Jun" || m == "June") return 6;
    if (m == "Jul" || m == "July") return 7;
    if (m == "Aug" || m == "August") return 8;
    if (m == "Sep" || m == "September") return 9;
    if (m == "Oct" || m == "October") return 10;
    if (m == "Nov" || m == "November") return 11;
    if (m == "Dec" || m == "December") return 12;
}

/* 构造函数定义 */
Date2::Date2(const string& s) {
    string::size_type pos = 0, last_pos = 0;
    if ((pos = s.find_first_of(' ', pos)) != string::npos) {
        month = month_val(s.substr(0, pos));
        ++ pos;
        last_pos = pos;
        if ((pos = s.find_first_of(',', pos)) != string::npos) {
            day = stoi(s.substr(last_pos, pos - last_pos));
            year = stoi(s.substr(++ ++ pos, 4));
        }
        else {
            pos = last_pos;
            pos = s.find_first_of(' ', pos);
            day = stoi(s.substr(last_pos, pos - last_pos));
            year = stoi(s.substr(++ pos, 4));
        }
    }
    else {
        pos = 0;
        pos = s.find_first_of('/', pos);
        day = stoi(s.substr(0, pos));
        ++ pos;
        last_pos = pos;
        pos = s.find_first_of('/', pos);
        month = stoi(s.substr(last_pos, pos - last_pos));
        year = stoi(s.substr(++ pos, 4));
    }
}

#endif
