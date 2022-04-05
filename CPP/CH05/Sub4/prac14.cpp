#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

// 查找连续出现次数最多的单词（没考虑多个最多的情况）

int main() {
    int maxCnt = 1, currentCnt = 1;
    string maxWord = "", currentWord = "";
    vector<string> svec = {};

    cout << "输入一组单词" << endl;
    while (cin >> currentWord) {
        svec.push_back(currentWord);
    }

    if (svec.size() < 2) {
        cerr << "输入单词数量小于2个" << endl;
        return -1;
    }

    auto it = svec.cbegin() + 1;
    for (; it != svec.cend(); ++ it) {
        if (*it == *(it - 1)) {
            ++ currentCnt;
            currentWord = *it;
        }
        else {
            if (currentCnt > maxCnt) {
                maxCnt = currentCnt;
                maxWord = currentWord;
            }
            currentCnt = 1;
        }
    }

    if (maxCnt == 1) {
        cout << "没有单词连续出现过" << endl;
    }
    else {
        cout << "连续出现次数最多的单词是：" << maxWord << ", 连续出现了" << maxCnt << "次。" << endl;
    }

    return 0;
}
