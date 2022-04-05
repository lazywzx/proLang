#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 将text第一段大写后输出
int main() {
    vector<string> text{"jslfjlsl fsflf fslsf fsl, ", "fsjf sfjew wlq qwp 99 fwppjf . ", 
    "jflsj jfls qqq. ", ""};
    for (auto it = text.begin(); it != text.end() && !it -> empty(); it ++) {
        for (auto &c : *it) {
            c = toupper(c);
        }
    }

    for (auto it = text.cbegin(); it != text.cend() && !it -> empty(); ++ it) {
        cout << *it << endl;
    }

    return 0;
}
