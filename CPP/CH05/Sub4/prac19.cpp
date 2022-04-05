#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 使用do while不断读入两个字符串，输出较短的那个

int main() {
    string rsp = "";
    do {
        cout << "输入两个长度不等的字符串" << endl;
        string s1 = "", s2 = "";
        cin >> s1 >> s2;
        (s1.size() <= s2.size()) ? (cout << s1) : (cout << s2);
        cout << endl;

        cout << "输入yes继续，输入其他终止" << endl;
        cin >> rsp;
    } while (rsp == "yes");

    return 0;
}
