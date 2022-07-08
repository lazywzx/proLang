#include <iostream>
#include <vector>

using namespace std;

// 计算杨辉三角

vector<vector<int>> generate(int numRows) {
    // 计算杨辉三角
    // 创建预留内存
     vector<vector<int>> res;
     res.reserve(numRows);  // numRows个vector<int>

     // 先创建第一个元素
     vector<int> v1{1};
     v1.reserve(1);
     res.push_back(v1);
     if (numRows > 1) {
         for (size_t i(1); i != numRows; ++ i) {
            // 第i行有i+1个元素
            vector<int> tmp(i + 1, 1);
            tmp.reserve(i + 1);
            tmp[1] = i;
            tmp[i - 1] = i;
            for (size_t j(2); j < i - 1; ++ j) {
                // 遍历该行中需要修改的元素
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            res.push_back(tmp);
        }
     }

     return res;
}

int main() {
    int numRows(7);
    auto res = generate(numRows);

    for (auto& v : res) {
        for (auto& i : v) {
            cout << i << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
