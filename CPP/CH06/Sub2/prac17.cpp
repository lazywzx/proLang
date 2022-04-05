#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ��д�����ж�string�������Ƿ��д�д��ĸ����д������string����ĳ�Сд

bool has_uppper(const string &s) {
    for (auto &c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

void to_lower(string &s) {
    for (auto &c : s) {
        c = tolower(c);
    }
}

int main() {
    string s = "heljfllwe, WlkljlflLLjJIfwef";
    cout << s << endl;

    if (has_uppper(s)) {
        cout << "�д�д��ĸ" << endl;
    }
    else {
        cout << "�޴�д��ĸ" << endl;
    }

    to_lower(s);
    cout << s << endl;

    return 0;
}
