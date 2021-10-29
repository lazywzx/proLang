#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 比较字符串
int main()
{
    string line1, line2;
    cout << "读入两个字符串：" << endl;

    getline(cin, line1);
    getline(cin, line2);

    if (line1 == line2)
    {
        cout << "相等" << endl;
    }
    else if (line1 > line2)
    {
        cout << line1 << endl;
    }
    else
    {
        cout << line2 << endl;
    }

   return 0;
}
