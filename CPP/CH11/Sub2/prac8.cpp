#include <iostream>
#include <string>
#include <set>

using namespace std;

// 在set中保存不重复单词

int main() {
    cout << "输入单词序列：" << endl;
    set<string> words;
    string word;
    while (cin >> word) {
        words.insert(word);
    }

    for(auto& w : words) {
        cout << w << "\t";
    }
    cout << endl;

    return 0;
}