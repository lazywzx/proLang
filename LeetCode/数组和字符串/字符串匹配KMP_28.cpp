#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 字符串匹配算法KMP，实现strStr()方法

void buildNext(vector<int>& next, string& s) {
    // 构造模式串s的next数组, s不能为空
    // next数组中的元素是s对应位置处的最大公共前后缀长度，next[0] = -1
    next[0] = -1;

    int i(-1);
    size_t sz(s.size()), j(0);
    while (j < sz - 1) {
        // 最后一个字符不管
        if (i < 0 || s[i] == s[j]) {
            ++ i;
            ++ j;
            next[j] = i;
        }
        else {
            i = next[i];    // 参考网上的算法
        }
    }
}

int strStr(string haystack, string needle) {
    // 找出在haystack中needle出现的第一个位置
    auto sz_h(haystack.size()), sz_n(needle.size());
    // 处理特殊情况
    if (!sz_n) {
        return 0;
    }
    // haystack更短，不可能包含needle
    if (sz_h < sz_n) {
        return -1;
    }

    vector<int> next(sz_n, 0);
    next.reserve(sz_n);
    buildNext(next, needle);    // 创建next数组

    size_t check_len(sz_h - sz_n), i(0);
    int j(0);
    // 当剩下的子串长度不足以放下needle时就可以结束了
    while (i <= check_len) {
        while (j >= 0 && j < sz_n && i < sz_h) {
            if (haystack[i] == needle[j]) {
                // 当j = -1时，i向右移动一位，从needle的开头重新匹配
                ++ i;
                ++ j;
            }
            else {
                j = next[j];
            }
        }
        if (j == sz_n) {
            return i - sz_n;    // 匹配成功，返回第一个匹配位置
        }
        ++ i;
        j = 0;
    }
    // 匹配失败
    return -1;
}

int main() {
    string h("wangwanwang"), n("wfjwflsjljlsflslfjl");
    auto res = strStr(h, n);

    cout << res << endl;

    return 0;
}
