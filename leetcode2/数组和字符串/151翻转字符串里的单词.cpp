#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 翻转字符串里的单词
// 每个单词用一个空格分隔
// 首尾没有空字符
// 字符串由大小写字母、数字和空格组成


string reverseWords(string s) {
    // 翻转字符串里的单词
    // 使用O(1)空间方法
    // s至少有一个单词
    auto sz = s.size();
    auto i(0), j(0);
    // 先将多余空格集中到字符串最后
    while (j < sz) {
        while (j < sz && s[j] == ' ') {
            // 寻找i后边的第一个字母
            ++ j;
        }
        while (j < sz && s[j] != ' ') {
            swap(s[i ++], s[j ++]); // 交换字符并向后滑动
        }
        ++ i;   // 留出一个空格
    }

    // 截取去除无多余空格的子串
    while (s[sz - 1] == ' ') {
        -- sz;
    }
    s = s.substr(0, sz);
    s.resize(sz);
    // 翻转字符串里的单词：两次翻转
    // 第一次翻转整个字符串，第二次翻转每个单词
    reverse(s.begin(), s.end());
    i = 0;
    j = 0;
    while (j < sz) {
        while (j < sz && s[j] != ' ') {
            ++ j;
        }
        // 翻转单词
        reverse(s.begin() + i, s.begin() + j);
        ++ j;
        i = j;
    }

    return s;
}


int main() {
    string word;
    cout << "输入句子" << endl;
    getline(cin, word);
    
    auto res = reverseWords(word);

    cout << res << endl;

    return 0;
}
