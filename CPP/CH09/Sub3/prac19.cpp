#include <iostream>
#include <list>
#include <string>

using namespace std;

// 从标准输入读取string序列存入list中，用迭代器打印

int main() {
    list<string> ls{};
    cout << "输入string序列" << endl;

    string word("");
    while (cin >> word) {
        ls.push_back(word);
    }

    for (auto lsb = ls.cbegin(), lse = ls.cend(); lsb != lse; ++ lsb) {
        cout << *lsb << " ";
    }
    cout << endl;

    return 0;
}
