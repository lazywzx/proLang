#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ʹ��while��������������εĵ���

int main() {
    string word = "", lastWord = "";
    bool flag = false;

    cout << "����һ�鵥��" << endl;
    while (cin >> word) {
        if (word == lastWord) {
            flag = true;
            break;
        }
        else {
            lastWord = word;
        }
    }

    flag ? (cout << lastWord) : (cout << "û�������������εĵ���");

    return 0;
}
