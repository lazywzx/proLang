#ifndef DATE_H
#define DATE_H

#include <istream>
#include <string>
#include <vector>

using namespace std;

/* Date�� */
class Date {
    /* ˽�� */
    private:
        /* ���ݳ�Ա */
        string time = "";   // ʱ��
        string address = "";    // �ص�
        string event = "";  // �¼�
    
    /* ���� */
    public:
        /* ���캯�� */
        Date(const string& t, const string& a, const string& e)
            : time(t), address(a), event(e) {}
        /* ί�й��캯�� */
        Date(): Date("", "", "") {}
        Date(const string& t, const string& a): Date(t, a, "") {}
        Date(istream& is): Date() {
            is >> time >> address >> event;
        }
        
};

#endif