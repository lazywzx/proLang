#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 排序并消除重复元素

// 打印容器
void print_v(vector<string>& v) {
    for (auto& s : v) {
        cout << s << "\t";
    }
    cout << endl;
}

void elimDups(vector<string>& words) {
    print_v(words);
    
    sort(words.begin(), words.end());
    print_v(words);

    auto end_iter = unique(words.begin(), words.end());
    print_v(words);

    words.erase(end_iter, words.end());
    print_v(words);
}

int main() {
    vector<string> vs{};
    cout << "输入单词序列：" << endl;
    string word;
    while (cin >> word) {
        vs.push_back(word);
    }

    elimDups(vs);

    return 0;
}