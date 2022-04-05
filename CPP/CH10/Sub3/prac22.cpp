#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

// 使用count_if统计长度小于等于6的单词数
// 使用函数代替lambda
// 使用bind

bool word_len(const string& s, const string::size_type& sz) {
    return (s.size() <= sz) ? true : false;
}

int count_words(const vector<string>& words, const string::size_type& sz) {
    return count_if(words.cbegin(), words.cend(), bind(word_len, _1, sz));
}

int main() {
    const vector<string> vs{"jflslffl", "woqjweoi", "jfjf", "jfw", "qqqs", "jfxx", "fjowofl", "fjslfl", "fjl"};
    const string::size_type sz = 6;
    int cnt = count_words(vs, sz);
    cout << "长度不超过" << sz << "的单词数：" << cnt << endl;

    return 0;
}
