#ifndef DATE_H
#define DATE_H

#include <istream>
#include <string>
#include <vector>

using namespace std;

/* Date类 */
class Date {
    /* 私有 */
    private:
        /* 数据成员 */
        string time = "";   // 时间
        string address = "";    // 地点
        string event = "";  // 事件
    
    /* 公有 */
    public:
        /* 构造函数 */
        Date(const string& t, const string& a, const string& e)
            : time(t), address(a), event(e) {}
        /* 委托构造函数 */
        Date(): Date("", "", "") {}
        Date(const string& t, const string& a): Date(t, a, "") {}
        Date(istream& is): Date() {
            is >> time >> address >> event;
        }
        
};

#endif