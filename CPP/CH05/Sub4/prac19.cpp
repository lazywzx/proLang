#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ʹ��do while���϶��������ַ���������϶̵��Ǹ�

int main() {
    string rsp = "";
    do {
        cout << "�����������Ȳ��ȵ��ַ���" << endl;
        string s1 = "", s2 = "";
        cin >> s1 >> s2;
        (s1.size() <= s2.size()) ? (cout << s1) : (cout << s2);
        cout << endl;

        cout << "����yes����������������ֹ" << endl;
        cin >> rsp;
    } while (rsp == "yes");

    return 0;
}
