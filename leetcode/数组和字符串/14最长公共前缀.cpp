#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 给定一个字符串数组（存储多个字符串的列表）
// 找到最长的公共前缀
// 若没有前缀则输出""
/*
string longestCommonPrefix(vector<string>& strs) {
    // 寻找最长公共前缀
    auto strs_len = strs.size();
    // 先处理特殊情况
    if (!strs_len) {
        return "";
    }
    if (strs_len == 1) {
        return strs[0];
    }

    // 找到最短的字符串，如果有长度为0的字符串，直接返回""
    size_t min_len(200);  // 每个字符串最长200个字符
    for (auto& s : strs) {
        auto sz(s.size());
        if (!sz) {
            return "";  // 如果有0长度字符串，那肯定没有公共前缀喽
        }
        if (sz < min_len) {
            min_len = sz;   // 找到最短的字符串长度，最多循环该长度次数
        }
    }

    // 对于每个字符，遍历整个列表
    string &s(strs[0]);
    size_t c(0);
    for (; c != min_len; ++ c) {
        for (size_t i(1); i != strs_len; ++ i) {
            if (strs[i][c] != s[c]) {
                // 遇到不匹配的情况就结束
                return string(s.cbegin(), s.cbegin() + c);
            }
        }
    }

    return string(s.cbegin(), s.cbegin() + c);
}
*/
string longestCommonPrefix(vector<string>& strs) {
    // 寻找最长公共前缀
    // 对原字符串列表排序
    if (!strs.size()) {
        return "";
    }
    sort(strs.begin(), strs.end()); // 默认优先按照长短排序，相同长度的按照字符排序
    // 判断第一个和最后一个字符串的最长公共子串
    auto &head(strs[0]), &tail(strs.back());
    size_t sz = (head.size() < tail.size()) ? head.size() : tail.size();
    size_t i(0);
    for (; i != sz; ++ i) {
        if (head[i] != tail[i]) {
            return string(head.cbegin(), head.cbegin() + i);
        }
    }

    return string(head.cbegin(), head.cbegin() + i);
}

int main() {
    vector<string> vs{
        "wangzixu",
        "wangzixu98",
        "wangfff",
        "wangziii",
        "wangvv"
    };

    auto res = longestCommonPrefix(vs);
    cout << res << endl;

    return 0;
}
