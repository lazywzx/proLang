#include <vector>
#include <iostream>
#include <set>

using namespace std;

// 当矩阵中某个元素为0时，将它所在行和列都置为0

void setZeroes(vector<vector<int>>& matrix) {
    // 当矩阵中某个元素为0时，将它所在行和列都置为0
    // 遍历整个数组，将0所在行和列的索引记录下来
    auto M(matrix.size()), N(matrix[0].size());
    vector<bool> row(M, false), col(N, false);
    for (size_t i(0); i != M; ++ i) {
        for (size_t j(0); j != N; ++ j) {
            // 记录下0的位置
            if (!matrix[i][j]) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // 遍历0元素的索引，将相应行和列置为0
    for (size_t i(0); i != M; ++ i) {
        for (size_t j(0); j != N; ++ j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix{
        {1, 2, 3, 4, 5},
        {0, 7, 0, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 0, 25}
    };

    for (auto& nums : matrix) {
        for (auto& n : nums) {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    setZeroes(matrix);
    for (auto& nums : matrix) {
        for (auto& n : nums) {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}
