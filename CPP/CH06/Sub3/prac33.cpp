#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// 使用递归函数输出vector中的内容

string print_v(vector<string> vs) {
    if (vs.size() > 1) {
        vector<string> s(vs.begin(), vs.end() - 1);
        return print_v(s) + *(vs.end() - 1);
    }
    return *vs.begin();
}

int main() {
    vector<string> s{"hello, ", "world!", "\t", "你好, ", "世界！"};
    cout << print_v(s) << endl;

    return 0;
}
