#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

// 输出大于指定长度的单词
// 使用check_size和bind

// 打印容器
void print_v(vector<string>& v) {
    for (auto& s : v) {
        cout << s << "\t";
    }
    cout << endl;
}

/* 按字典序排列并消除重复元素 */
void elimDups(vector<string>& words) {
    print_v(words);
    
    sort(words.begin(), words.end());
    print_v(words);

    auto end_iter = unique(words.begin(), words.end());
    print_v(words);

    words.erase(end_iter, words.end());
    print_v(words);
}

// 二元谓词，长度小的返回true，排在前边
auto len = [](const string& s1, const string& s2) -> bool {
    return s1.size() < s2.size();
};

bool check_size(const string& s, string::size_type sz) {
    return s.size() >= sz;
}

void biggies(vector<string>& words, string::size_type sz) {
    elimDups(words);    // 按字典排序，消除重复单词
    // 按长度排序，相同长度保持字典序
    stable_sort(words.begin(), words.end(), len);
    print_v(words);
    // 查找长度大于sz的元素的第一个位置
    // 保持字典序
    auto end_iter = stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
    // 统计长度大于等于sz的单词数
    auto cnt = end_iter - words.begin();
    cout << "长度大于等于" << sz << "的单词数：" << cnt << endl;
    // 打印长度大于等于sz的单词，每个单词后接空格
    auto space = [](const string& s) -> void {
        cout << s << " ";
    };
    for_each(words.begin(), end_iter, space);
    cout << endl;
}

int main() {
    vector<string> vs{"jklfsl", "sjfowoi", "uuuu", "ertyuio", "jfjsjjfslfls", "jjfss", "ss", "ppo"};
    biggies(vs, 5);

    return 0;
}
