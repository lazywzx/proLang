#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 使用while检查连续出现两次的单词

int main() {
    string word = "", lastWord = "";
    bool flag = false;

    cout << "输入一组单词" << endl;
    while (cin >> word) {
        if (word == lastWord) {
            flag = true;
            break;
        }
        else {
            lastWord = word;
        }
    }

    flag ? (cout << lastWord) : (cout << "没有连续出现两次的单词");

    return 0;
}
