#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ʹ��while��������������ε����Դ�д��ĸ��ͷ�ĵ���

int main() {
    string word = "", lastWord = "";
    bool flag = false;

    cout << "����һ�鵥��" << endl;
    while (cin >> word) {
        if (!word.empty()) {
            if (!isupper(word[0])) {
                lastWord = word;
                continue;
            }
            if (word == lastWord) {
                flag = true;
                break;
            }
            else {
                lastWord = word;
            }
        }
        else {
            lastWord = word;
        }
    }

    flag ? (cout << lastWord) : (cout << "û�������������εĵ���");

    return 0;
}
