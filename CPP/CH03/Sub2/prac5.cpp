#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 连接字符串
int main()
{
    string line;
    string tmp;
    while (getline(cin, tmp))
    {
        if (tmp != "")
        {
            line = line + " " + tmp;
        }
        else
        {
            break;
        }
    }

    cout << line << endl;

    return 0;    
}
