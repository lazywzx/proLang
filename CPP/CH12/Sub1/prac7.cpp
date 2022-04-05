#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// 函数返回动态分配的vector<int>，传递给输入函数，再传递给输出函数
// 使用智能指针shared_ptr

shared_ptr<vector<int>> create_v() {
    return make_shared<vector<int>>();
}

/* 输入函数 */
void input_v(shared_ptr<vector<int>> vp) {
    cout << "输入整数序列" << endl;
    int num;
    while (cin >> num) {
        vp->push_back(num);
    }
}

/* 输出函数 */
void output_v(shared_ptr<vector<int>> vp) {
    for (auto& n : *vp) {
        cout << n << "\t";
    }
    cout << endl;
}

int main() {
    auto vp = create_v();   // 创建动态内存
    input_v(vp);   // 输入数列
    output_v(vp);   // 输出

    return 0;
}
