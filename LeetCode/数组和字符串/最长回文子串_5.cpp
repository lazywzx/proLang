#include <iostream>
#include <string>

using namespace std;

// 寻找最长回文子串
// 在字符串后半段判断是否可能还有更长的回文子串
// 若无，则直接结束

inline void check(string& s, size_t& sz, size_t& max_len, size_t& mr, int& ml, size_t r, int l) {
    // 判断是否有已i为中心的回文子串
    // 如有，更新最大长度
    while (l >= 0 && r < sz) {
        if (s[l] != s[r]) {
            break;
        }
        -- l;
        ++ r;
    }
    if (r -l - 1 > max_len) {
        max_len = r - l - 1;
        mr = r;
        ml = l;
    }
}

string longestPalindrome(string s) {
    // 寻找最长回文子串
    auto sz(s.size());
    // 先判断特殊情况
    if (sz < 2) {
        return s;
    }

    size_t i(0), max_len(0), mr(0);
    int ml(0);
    for (; i != sz - 1; ++ i) {
        // 最后一个字符：没有以最后一个字符为中心的奇/偶长度子串
        // 在前半段
        if (i <= sz / 2) {
            // 奇数
            check(s, sz, max_len, mr, ml, i + 1, i - 1);
            // 偶数
            check(s, sz, max_len, mr, ml, i + 1, i);
        }
        else {
            // 在后半段
            // 先判断是否还有可能更长的子串
            if (max_len < ((sz - i) * 2 + 1)) {
                check(s, sz, max_len, mr, ml, i + 1, i - 1);
                check(s, sz, max_len, mr, ml, i + 1, i);
            }
            else {
                break;
            }
        }
    }
    // 返回ml + 1到mr - 1之间的字符串
    return string(s.cbegin() + ml + 1, s.cbegin() + mr);
}

int main() {
    string s;
    cout << "输入字符串" << endl;
    cin >> s;
    auto res = longestPalindrome(s);
    cout << res << endl;

    return 0;
}
