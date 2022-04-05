#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 读入一组词，放入vector，所有词改为大写
int main() {
    string word;
    vector<string> words;

    while (cin >> word) {
        words.push_back(word);
    }
    
    for (auto &w : words) {
        for (auto &c : w) {
            c = toupper(c);
        }
    }
    cout << "容量：" << words.size() << endl;
    cout << "内容：" << endl;
    for (auto &w : words) {
        cout << w << endl;
    }

    return 0;
}
