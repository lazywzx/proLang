#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用泛型算法count统计给定值出现次数

int main() {
    cout << "输入int序列：" << endl;

    vector<int> vi{};
    int val;
    while (cin >> val) {
        vi.push_back(val);
    }
    
    cout << "输入要统计的值：" << endl;
    cin >> val;
    
    // 统计次数
    auto cnt = count(vi.cbegin(), vi.cend(), val);
    cout << val << " 出现了 " << cnt << " 次。" << endl;

    return 0;
}