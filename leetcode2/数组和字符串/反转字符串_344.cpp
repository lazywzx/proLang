#include <iostream>
#include <vector>

using namespace std;

// 反转字符数组

/* 双指针的效率可能并不高
void reverseString(vector<char>& s) {
    // 原地反转字符数组
    // s至少有一个元素
    size_t i(0), j(s.size() - 1);
    while (i < j) {
        swap(s[i ++], s[j --]);
    }
}
*/

// 单指针
void reverseString(vector<char>& s) {
    // 原地反转字符数组，单指针
    // s至少有一个字符
    // 处理特殊情况
    auto sz(s.size());
    if (sz != 1) {
        for (int i(0); i != sz / 2; ++ i) {
            swap(s[i], s[sz - 1 - i]);
        }
    }
}

int main() {
    vector<char> s{'w', 'a', 'n', 'g', 'z', 'i', 'x', 'u'};
    for (auto& c : s) {
        cout << c << " ";
    }
    cout << endl;

    reverseString(s);
    for (auto& c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
