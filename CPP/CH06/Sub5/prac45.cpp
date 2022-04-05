#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 使用默认实参输出单数/复数单词, 使用内联函数

inline string my_make_plural(size_t ctr, const string& word, const string& ending = "s") {
    return (ctr < 2) ? word : word + ending;
}

int main() {
    cout << my_make_plural(1, "success") << endl;
    cout << my_make_plural(2, "success", "es") << endl;

    cout << my_make_plural(1, "failure") << endl;
    cout << my_make_plural(2, "failure") << endl;

    return 0;
}
