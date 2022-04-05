#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 给main传递参数，连接两个字符串

int main(int argc, char* argv[]) {
    string s = "";
    s = argv[1] + s + argv[2];
    cout << s << endl;

    return 0;
}
