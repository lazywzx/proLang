#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

// 统计list中的某个string出现次数

int main() {
    cout << "输入单词序列：" << endl;

    list<string> ls{};
    string word;
    while (cin >> word) {
        ls.push_back(word);
    }
    
    cin.clear();
    cout << "输入要统计的单词：" << endl;
    cin >> word;
    auto cnt = count(ls.cbegin(), ls.cend(), word);
    cout << word << " 出现了 " << cnt << " 次。" << endl;

    return 0;
}
