#include <iostream>
#include <string>

using namespace std;

// 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

string reverseWords(string s) {
    // 反转字符串中每个单词内部字符的顺序
    auto sz(s.size());
    size_t i(0), j(0), i_cp;
    
    while (i < sz) {
        while (i < sz && s[i] != ' ') {
            ++ i;
        }
        i_cp = i - 1;

        // 翻转一个单词内部字符
        while (j < i_cp) {
            swap(s[j ++], s[i_cp --]);
        }
        
        ++ i;
        j = i;
    }

    return s;
}

int main() {
    string s("wang zi xu");

    auto res = reverseWords(s);
    cout << res << endl;

    return 0;
}
