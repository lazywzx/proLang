#include <iostream>
#include <deque>
#include <string>

using namespace std;

// 从标准输入读取string序列存入deque中，用迭代器打印

int main() {
    deque<string> ds{};
    cout << "输入string序列" << endl;

    string word("");
    while (cin >> word) {
        ds.push_back(word);
    }

    for (auto dsb = ds.cbegin(), dse = ds.cend(); dsb != dse; ++ dsb) {
        cout << *dsb << " ";
    }
    cout << endl;

    return 0;
}
