#include <iostream>
#include <map>
#include <string>

using namespace std;

// 使用map迭代器向元素赋值

int main() {
    map<string, int> msi{
        {"zhang", 1},
        {"wang", 0}
    };

    auto m_iter = msi.begin();  // 按字典序排列
    m_iter->second = 6;

    // 打印
    while (m_iter != msi.end()) {
        cout << m_iter->first << "\t" << m_iter->second << endl;
        ++ m_iter;
    }

    return 0;
}