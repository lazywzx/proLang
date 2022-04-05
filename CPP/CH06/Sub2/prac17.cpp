#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 编写函数判断string对象中是否有大写字母；编写函数将string对象改成小写

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
        cout << "有大写字母" << endl;
    }
    else {
        cout << "无大写字母" << endl;
    }

    to_lower(s);
    cout << s << endl;

    return 0;
}
