#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
*/

/*
int firstUniqChar(string s) {
    // 返回第一个非重复字符的索引
    unordered_map<char, size_t> smap;
    for (char &c : s) {
        // 对于不存在的c，smap[c]进行值初始化为0
        ++ smap[c];
    }

    for (char &c : s) {
        if (smap[c] == 1) {
            return s.find(c);
        }
    }

    return -1;
}
*/


int firstUniqChar(string s) {
    // 返回第一个非重复字符的索引
    // 用数组的效率更高
    int smap[26] = {0};
    for (char &c : s) {
        ++ smap[c - 'a'];
    }

    for (char &c : s) {
        if (smap[c - 'a'] == 1) {
            return s.find(c);
        }
    }

    return -1;
}


int main() {
    string s("leetcode");
    auto res(firstUniqChar(s));

    cout << res << endl;

    return 0;
}
