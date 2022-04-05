#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 返回string数组的引用

string (&str_ref(string (&s)[6]))[6] {
    return s;
}


int main() {
    string s[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    for (auto &ss : str_ref(s)) {
        cout << ss << "\t";
    }
    cout << endl;
    
    return 0;
}


