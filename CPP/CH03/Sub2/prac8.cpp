#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 使用while或传统for将字符串所有字符修改为X
int main()
{
    string line;
    cout << "输入一段字符串" << endl;
    while (getline(cin, line)) {
        if (!line.empty()) {
            for (decltype(line.size()) ls = 0; ls < line.size(); ls ++) {
                line[ls] = 'X';
            }
            /*
            decltype(line.size()) ls = 0;
            while (ls < line.size()) {
                line[ls] = 'X';
                ++ ls;
            }
            */
            cout << "修改所有字符为X" << endl;
            cout << line << endl;
        }
        else {
            cout << "empty string!" << endl;
        }
    }

    return 0;    
}
