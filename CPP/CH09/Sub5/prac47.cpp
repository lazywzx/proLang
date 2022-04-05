#include <iostream>
#include <string>

using namespace std;

// 查找数字字符和字母字符
// 分别使用find_first_of和find_first_not_of

int main() {
    string s("ab2c3d7R4E6");

    /* 数字 */
    string number;
    number.reserve(10);

    /* 大写字母 */
    string ualpha;
    ualpha.reserve(26);
    
    /* 小写字母 */
    string lalpha;
    lalpha.reserve(26);

    /* 其他字符 */
    string other;
    other.reserve(66);
    
    char c;
    for (unsigned i = 0; i != 128; ++ i) {
        c = i;
        if (i < 48) {
            other.push_back(c);
        }
        else if (i < 58) {
            number.push_back(c);
        }
        else if (i < 65) {
            other.push_back(c);
        }
        else if (i < 91) {
            ualpha.push_back(c);
        }
        else if (i < 97) {
            other.push_back(c);
        }
        else if (i < 123) {
            lalpha.push_back(c);
        }
        else {
            other.push_back(c);
        }
    }

    // find_first_of
    cout << "find_first_of" << endl;
    cout << "数字出现位置：" << endl;
    string::size_type pos = 0;
    while ((pos = s.find_first_of(number, pos)) != string::npos) {
        cout << pos << "\t";
        ++ pos;
    }
    cout << endl;

    cout << "字母出现的位置：" << endl;
    pos = 0;
    while ((pos = s.find_first_of(ualpha + lalpha, pos)) != string::npos) {
        cout << pos << "\t";
        ++ pos;
    }
    cout << endl;

    // find_first_not_of
    cout << "find_first_not_of" << endl;
    cout << "数字出现位置：" << endl;
    pos = 0;
    while ((pos = s.find_first_not_of(ualpha + lalpha + other, pos)) != string::npos) {
        cout << pos << "\t";
        ++ pos;
    }
    cout << endl;

    cout << "字母出现的位置：" << endl;
    pos = 0;
    while ((pos = s.find_first_not_of(number + other, pos)) != string::npos) {
        cout << pos << "\t";
        ++ pos;
    }
    cout << endl;

    return 0;
}
