#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// �ֱ�ʹ�����ͱ�����β�÷������͡�decltype��������������string���������

typedef string sr[6];
sr& str_ref1(string (&s)[6]) {
    return s;
}

auto str_ref2(string (&s)[6]) -> string (&)[6] {
    return s;
}

string s2[6];
decltype(s2) &str_ref3(string (&s)[6]) {
    return s;
}


int main() {
    string s[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    for (auto &ss : str_ref1(s)) {
        cout << ss << "\t";
    }
    cout << endl;

    for (auto &ss : str_ref2(s)) {
        cout << ss << "\t";
    }
    cout << endl;

    for (auto &ss : str_ref3(s)) {
        cout << ss << "\t";
    }
    cout << endl;

    return 0;
}


