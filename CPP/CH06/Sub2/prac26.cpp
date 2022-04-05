#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 将传递给main的实参输出

int main(int argc, char* argv[]) {
    string s = "";
    for (int i = 1; i != argc; ++ i) {
        cout << s + argv[i] << "\t";
    }
    cout << endl;

    return 0;
}
