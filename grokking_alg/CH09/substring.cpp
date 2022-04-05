#include <iostream>
#include <string>
#include <set>

using namespace std;

// 给定一个单词，从待选单词中找出最相似
// 准则：最长公共子串

int len_substring(const string& s, const string& maybe) {
    /* 比较两个字符串的公共子串长度，对齐顶点，按顺序比较 */
    size_t sz_s = s.size(), sz_mb = maybe.size();
    // 建立网格
    int mesh[sz_s][sz_mb] = {0};
    int maxlen = 0;
    // 先填充第一行
    for (size_t j = 0; j != sz_mb; ++ j) {
        if (s[0] == maybe[j]) {
            mesh[0][j] = 1;
            maxlen = 1;
        }
    }
    // 再填充第一列
    for (size_t i = 0; i != sz_s; ++ i) {
        if (s[i] == maybe[0]) {
            mesh[i][0] = 1;
            maxlen = 1;
        }
    }
    // 遍历网格，从第二行，第二列开始
    for (size_t i = 1; i != sz_s; ++ i) {
        for (size_t j = 1; j != sz_mb; ++ j) {
            if (s[i] == maybe[j]) {
                // 当前结果加上左上角结果
                mesh[i][j] = mesh[i - 1][j - 1] + 1;
                if (mesh[i][j] > maxlen) {
                    maxlen = mesh[i][j];    // 更新最大值
                }
            }
        }
    }
    // 返回公共子串长度
    return maxlen;
}

string maxlen_substring(const string& s, const set<string>& s_set) {
    /* 在待选字符串中找出具有最长公共子串的那个 */
    int maxlen = 0, len = 0;
    string res("");
    for (auto& s_mb : s_set) {
        // 遍历所有待选字符串
        len = len_substring(s, s_mb);
        if (len > maxlen) {
            maxlen = len;
            res = s_mb;
        }
    }

    return res;
}

int main() {
    // 给定字符串与待选字符串
    string s("subsrng");
    // 此示例不合适，待选字符串中只能出现真实存在的单词
    set<string> s_set{"subbing", "aubstrig", "substring", "sustrin", "dustriiing"};
    auto res = maxlen_substring(s, s_set);

    cout << res << endl;

    return 0;
}
