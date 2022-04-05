#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcpy;
using std::strcat;

// 连接字符数组
const char c1[] = "this is c1.";
const char c2[] = "this is c2.";
char c3[23];

int main() {
    cout << c1 << endl;
    cout << c2 << endl;
    strcpy(c3, c1);
    strcat(c3, c2);
    cout << c3 << endl;

    return 0;
}

