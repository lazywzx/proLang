#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 剔除字符串中的标点符号
int main()
{
    string line;
    string result;
    cout << "输入一段带标点符号的字符串" << endl;
    while (getline(cin, line)) {
        if (!line.empty()) {
            for (auto &c : line) {
                if (!ispunct(c)) {
                    result += c;
                }
            }
            cout << "剔除标点符号" << endl;
            cout << result << endl;
        }
        else {
            cout << "empty string!" << endl;
        }
    }

    return 0;    
}
