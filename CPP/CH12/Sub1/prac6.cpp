#include <iostream>
#include <vector>
#include <new>

using namespace std;

// 函数返回动态分配的vector<int>，传递给输入函数，再传递给输出函数
// 使用delete适时删除

vector<int>* create_v() {
    return new vector<int>;
}

/* 输入函数 */
vector<int>* input_v(vector<int>* vp) {
    cout << "输入整数序列" << endl;
    int num;
    while (cin >> num) {
        vp->push_back(num);
    }

    return vp;
}

/* 输出函数 */
void output_v(vector<int>* vp) {
    for (auto& n : *vp) {
        cout << n << "\t";
    }
    cout << endl;
}

int main() {
    vector<int>* vp = create_v();   // 创建动态内存
    vp = input_v(vp);   // 输入数列
    output_v(vp);   // 输出
    // 删除动态内存
    delete vp;

    return 0;
}
