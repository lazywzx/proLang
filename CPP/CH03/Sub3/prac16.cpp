#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// ��֤vector����
int main() {
    vector<int> v1; // һ���յ�int������
    cout << "v1������" << v1.size() << endl;
    cout << "v1���ݣ�" << endl;
    for (auto &v : v1) {
        cout << v << "\t";
    }
    cout << endl;
    
    vector<int> v2(10); // 10��int��Ԫ�أ�ֵΪ0
    cout << "v2������" << v2.size() << endl;
    cout << "v2���ݣ�" << endl;
    for (auto &v : v2) {
        cout << v << "\t";
    }
    cout << endl;

    vector<int> v3(10, 42); // 10��int��Ԫ�أ�ֵΪ42
    cout << "v3������" << v3.size() << endl;
    cout << "v3���ݣ�" << endl;
    for (auto &v : v3) {
        cout << v << "\t";
    }
    cout << endl;

    vector<int> v4{10}; // 1��int��Ԫ�أ�ֵΪ10
    cout << "v4������" << v4.size() << endl;
    cout << "v4���ݣ�" << endl;
    for (auto &v : v4) {
        cout << v << "\t";
    }
    cout << endl;

    vector<int> v5{10, 42}; // 2��int��Ԫ�أ�ֵΪ10��42
    cout << "v5������" << v5.size() << endl;
    cout << "v5���ݣ�" << endl;
    for (auto &v : v5) {
        cout << v << "\t";
    }
    cout << endl;

    vector<string> v6{10};  // 10����string�ַ���
    cout << "v6������" << v6.size() << endl;
    cout << "v6���ݣ�" << endl;
    for (auto &v : v6) {
        cout << v << "\t";
    }
    cout << endl;

    vector<string> v7{10, "hi"};    // 10���ַ�����ֵΪ"hi"
    cout << "v7������" << v7.size() << endl;
    cout << "v7���ݣ�" << endl;
    for (auto &v : v7) {
        cout << v << "\t";
    }
    cout << endl;
    
    return 0;
}
