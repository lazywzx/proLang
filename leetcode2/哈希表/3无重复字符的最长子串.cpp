#include <string>
#include <memory.h>

using namespace std;

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/


/*
int lengthOfLongestSubstring(string s) {
    // 寻找相邻重复字符的最大距离
    auto sz(s.size());
    if (sz < 2) {
        return sz;
    }

    int smap[128];
    memset(smap, -1, sizeof(smap));

    int maxlen(1), cut_index(-1);
    for (int i(0); i != sz; ++ i) {
        // 对于每个元素，其索引减去阶段处索引
        if (smap[s[i]] != -1) {
            // 已存在
            maxlen = max(maxlen, i - cut_index - 1);
            cut_index = smap[s[i]];
            memset(smap, -1, sizeof(smap));
            // 从cut_index处重新建立映射
            i = cut_index;
        }
        else {
            maxlen = max(maxlen, i - cut_index);
            smap[s[i]] = i;
        }
    }

    return maxlen;
}
*/


int lengthOfLongestSubstring(string s) {
    // 寻找相邻重复字符的最大距离
    // 使用滑动窗口
    // 参考题解
    auto sz(s.size());
    if (sz < 2) {
        return sz;
    }

    bool smap[128];
    memset(smap, false, sizeof(smap));

    int i(0), j(1);
    int maxlen(1);
    smap[s[0]] = true;
    for (; i != sz; ++ i) {
        while (!smap[s[j]] && j != sz) {
            // 没有重复，一直往下走
            smap[s[j]] = true;
            ++ j;
        }

        // 更新最大长度
        maxlen = max(maxlen, j - i);
        if (j == sz) {
            return maxlen;
        }
        // 去掉最前面的映射
        smap[s[i]] = false;
    }

    return maxlen;
}
