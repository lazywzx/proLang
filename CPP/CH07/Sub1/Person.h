#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;

struct Person
{
    /* ���Ա */
    string name = "";
    string address = "";

    /* ��Ա���� */
    string who() {
        // ��������
        return name;
    }

    string where() {
        // ����סַ
        return address;
    }

    /* ���캯�� */
    Person() = default;
    Person(const string& n, const string& a): name(n), address(a) {}
    Person(istream& is) {
        is >> name >> address;
    }

};

// �ǳ�Ա����
istream& read(istream& is, Person& p) {
    is >> p.name >> p.address;

    return is;
}

ostream& print(ostream& os, Person& p) {
    os << "name: " << p.who() << "address: " << p.where();

    return os;
}

#endif