#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
给定两个字符串 s 和 t ，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
*/

/* 咋说呢，集合映射啥的最大特点就是效率低
bool Isomorphic(string& s, string& t) {
    unordered_map<char, char> str_map;
    for (int i(0); i != s.size(); ++ i) {
        if (str_map.insert({s[i], t[i]}).first->second != t[i]) {
            // 如果插入失败且映射关系与之前的冲突
            return false;   // 能够保证相同字符只能映射到同一个字符上
        }
    }

    return true;
}


bool isIsomorphic(string s, string t) {
    // 判断s和t是否为同构字符串
    if (Isomorphic(s, t) && Isomorphic(t, s)) {
        return true;
    }

    return false;
}
*/


bool isIsomorphic(string s, string t) {
    // 判断s和t是否为同构字符串
    // 方法2：判断s的每个字符的位置与t对应字符位置是否一致
    for (size_t i(0); i != s.size(); ++ i) {
        if (s.find(s[i]) != t.find(t[i])) {
            return false;
        }
    }

    return true;
}


/*
bool Isomorphic(string& s, string& t) {
    // 判断s和t是否为同构字符串
    // 方法3：通过两个数组建立映射关系
    // 数组默认初始化为空
    vector<char> nums(128);
    nums.reserve(128);
    for (size_t i(0); i != s.size(); ++ i) {
        if (!nums[s[i]]) {
            nums[s[i]] = t[i];
        }
        else if (nums[s[i]] != t[i]) {
            return false;
        }
    }

    return true;
}

bool isIsomorphic(string s, string t) {
    // 判断s和t是否为同构字符串
    // 方法3：通过数组建立映射关系
    if (Isomorphic(s, t) && Isomorphic(t, s)) {
        return true;
    }

    return false;
}
*/


int main() {
    string s("paper"), t("title");
    auto res(isIsomorphic(s, t));

    cout << res << endl;

    return 0;
}
