#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。
可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，
所有源单词中的字母通常恰好只用一次。
*/


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // 字母异位词分组
    // 通过排序将同一组的词变成一致的键
    unordered_map<string, size_t> strsmap;
    size_t class_index(0);

    vector<vector<string>> res;
    for (auto &s : strs) {
        auto tmp(s);
        sort(s.begin(), s.end());   // 异位词排序后变成相同的字符串
        if (strsmap.find(s) != strsmap.end()) {
            // 已有此类，将原字符串加入此类
            res[strsmap[s]].emplace_back(tmp);
        }
        else {
            // 没有此类，创建此类
            strsmap[s] = class_index;
            ++ class_index;
            res.emplace_back(vector<string>({tmp}));
        }
    }

    return res;
}
