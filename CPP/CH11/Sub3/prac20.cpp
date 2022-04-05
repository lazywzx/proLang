#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

// 单词计数器
// 忽略大小写和标点
// 使用insert代替下标

int main() {
    cout << "输入单词序列" << endl;
    /* 需要过滤的单词 */
    set<string> nocnt{"a", "an", "the", "or"};
    /* 字典 */
    map<string, size_t> words;
    /* 读取输入 */
    string word;
    while (cin >> word) {
        /* 删除标点并统一为小写 */
        if (ispunct(*(word.crbegin()))) {
            word.erase(word.size() - 1);
        }
        word[0] = tolower(word[0]);

        /* 插入元素 */
        auto ret = words.insert(make_pair(word, 1));
        if (!ret.second) {
            ++ ret.first->second;
        }
    }

    /* 输出统计结果 */
    for(auto& w : words) {
        cout << w.first << " 出现了 " << w.second << " 次。" << endl;
    }

    return 0;
}