#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ʹ����������

inline bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int main() {
    string s1("hello, "), s2("world!hh");
    cout << isShorter(s1, s2) << endl;

    return 0;
}
