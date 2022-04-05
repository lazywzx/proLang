#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;

/* Person类 */
class Person {
    /* 友元声明 */
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, const Person&);
    /* 私有 */
    private:
        /* 类成员 */
        string name = "";
        string address = "";
    
    /* 公有 */
    public:
        /* 成员函数 */
        string who() {
            // 返回姓名
            return name;
        }

        string where() {
            // 返回住址
            return address;
        }

        /* 构造函数 */
        Person() = default;
        Person(const string& n, const string& a): name(n), address(a) {}
        Person(istream& is) {
            is >> name >> address;
        }

};

// 非成员函数
istream& read(istream& is, Person& p) {
    is >> p.name >> p.address;

    return is;
}

ostream& print(ostream& os, Person& p) {
    os << "name: " << p.who() << "address: " << p.where();

    return os;
}

#endif