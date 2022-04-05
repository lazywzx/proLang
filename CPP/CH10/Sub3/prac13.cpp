#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 使用partition划分长度大于5的单词

inline bool bigger_5(const string& s) {
    return (s.size() >= 5) ? true : false;
}

int main() {
    vector<string> vs{"qwer", "jflsls", "fjjf", "yuiop", "ghjnm", "sss", "wsdhifjo"};
    auto end_iter = partition(vs.begin(), vs.end(), bigger_5);

    for (auto iter = vs.cbegin(); iter != end_iter; ++ iter) {
        cout << *iter << "\t";
    }
    cout << endl;

    return 0;
}
