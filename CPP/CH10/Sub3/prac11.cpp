#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 使用谓词，指定排序方式，向算法传递函数

bool isShoter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

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

int main() {
    vector<string> vs{};
    cout << "输入单词序列：" << endl;
    string word;
    while (cin >> word) {
        vs.push_back(word);
    }

    elimDups(vs);

    stable_sort(vs.begin(), vs.end(), isShoter);
    print_v(vs);

    return 0;
}