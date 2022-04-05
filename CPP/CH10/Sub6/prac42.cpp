#include <iostream>
#include <string>
#include <list>

using namespace std;

// 使用链表的成员函数，消除重复单词

void elimDups(list<string>& words) {
    // 按字典序排序
    words.sort();
    // 消除重复单词
    words.unique();
}

int main() {
    list<string> ls{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(ls);
    for (auto& s : ls) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
