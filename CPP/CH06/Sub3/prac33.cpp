#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// ʹ�õݹ麯�����vector�е�����

string print_v(vector<string> vs) {
    if (vs.size() > 1) {
        vector<string> s(vs.begin(), vs.end() - 1);
        return print_v(s) + *(vs.end() - 1);
    }
    return *vs.begin();
}

int main() {
    vector<string> s{"hello, ", "world!", "\t", "���, ", "���磡"};
    cout << print_v(s) << endl;

    return 0;
}
