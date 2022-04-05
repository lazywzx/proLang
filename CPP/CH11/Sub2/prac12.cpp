#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// 读入string和int序列存入pair，存入vector
// 使用三种创建pair的方法

int main() {
    cout << "输入字符串 整数序列" << endl;
    vector<pair<string, int>> vp;
    string s;
    int i;
    pair<string, int> p;
    while (cin >> s >> i) {
        // vp.push_back(make_pair(s, i));
        // vp.push_back({s, i});
        p = {s, i};
        vp.push_back(p);
    }

    /* 输出 */
    for (auto& v : vp) {
        cout << v.first << ": " << v.second << endl;
    }

    return 0;
}
