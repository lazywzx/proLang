#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// 使用调试帮助，输出信息

string print_v(vector<string> vs) {
    #ifndef NDEBUG
        cout << "Info: " << __FILE__
             << ": in function " << __func__
             << " at line " << __LINE__ << endl
             << "Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "The vector size is " << vs.size() << endl;
    #endif
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
