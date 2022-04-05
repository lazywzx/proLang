#include <iostream>
#include <string>
#include <set>

using namespace std;

// 给定字符串，从待选字符串中找出与该字符串有最长公共子序列的那个
// 准则：最长公共子序列

int len_subsequence(const string& s, const string& maybe) {
    /* 使用动态规划计算两个字符串公共子序列，首端对齐，按顺序比较每个字符 */
    size_t sz_s = s.size(), sz_mb = maybe.size();
    // 建立网格
    int mesh[sz_s][sz_mb] = {0};
    // 先填充第一格
    if (s[0] == maybe[0]) {
        mesh[0][0] = 1;
    }
    // 再填充第一行和第一列
    for (size_t j = 1; j != sz_mb; ++ j) {
        if (s[0] == maybe[j]) {
            mesh[0][j] = 1; // 第一行的左上角不存在（可认为是0）
        }
        else {
            mesh[0][j] = mesh[0][j - 1];    // 第一行只有左边的值
        }
    }
    for (size_t i = 1; i != sz_s; ++ i) {
        if (s[i] == maybe[0]) {
            mesh[i][0] = 1;
        }
        else {
            mesh[i][0] = mesh[i - 1][0];    // 第一列只有右边的值
        }
    }
    // 最后遍历整个网格，从第二行第二列开始
    for (size_t i = 1; i != sz_s; ++ i) {
        for (size_t j = 1; j != sz_mb; ++ j) {
            if (s[i] == maybe[j]) {
                mesh[i][j] = mesh[i - 1][j - 1] + 1;
            }
            else {
                // 选左边或上边最大的
                mesh[i][j] = max(mesh[i - 1][j], mesh[i][j - 1]);
            }
        }
    }

    // 最后一格是结果
    return mesh[sz_s - 1][sz_mb - 1];
}

string maxlen_subsequence(const string& s, const set<string>& s_set) {
    /* 从待选字符串中找出与给定字符串有最长子序列的那个 */
    int maxlen = 0, current_len = 0;
    string res("");
    // 遍历所有字符串
    for (auto& s_mb : s_set) {
        current_len = len_subsequence(s, s_mb);
        if (current_len > maxlen) {
            maxlen = current_len;
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
    auto res = maxlen_subsequence(s, s_set);

    cout << res << endl;

    return 0;
}
