#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 使用范围for将所有字符改为"X"
int main()
{
    string line;
    cout << "输入一段字符串" << endl;
    while (getline(cin, line)) {
        if (!line.empty()) {
            for (auto &c : line) {
                c = 'X';
            }
            cout << "修改所有字符为X" << endl;
            cout << line << endl;
        }
        else {
            cout << "empty string!" << endl;
        }
    }

    return 0;    
}
