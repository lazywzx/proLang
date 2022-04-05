#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 使用count_if统计长度超过6的单词数

int count_words(const vector<string>& words, const vector<string>::size_type& sz) {
    auto len = [sz](const string& s) -> bool {
        return s.size() > sz;
    };

    return count_if(words.cbegin(), words.cend(), len);
}

int main() {
    const vector<string> vs{"jflslffl", "woqjweoi", "jfjf", "jfw", "qqqs", "jfxx", "fjowofl", "fjslfl", "fjl"};
    const vector<string>::size_type sz = 6;
    int cnt = count_words(vs, sz);
    cout << "长度超过" << sz << "的单词数：" << cnt << endl;

    return 0;
}
