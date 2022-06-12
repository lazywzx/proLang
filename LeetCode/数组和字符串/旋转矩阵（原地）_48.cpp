#include <iostream>
#include <vector>

using namespace std;

// 原地旋转矩阵
// 使用swap函数

void rotateMatrix(vector<vector<int>>& matrix) {
    // 方阵原地旋转矩阵
    auto N = matrix.size();
    // 水平翻转
    for (size_t i(0); i < N; ++ i) {
        // 遍历所有行的前半部分
        for (size_t j(0); j < N / 2; ++ j) {
            swap(matrix[i][j], matrix[i][N - 1 - j]);   // 交换元素
        }
    }

    // 反对角线交换元素
    for (size_t i(0); i < N - 1; ++ i) {
        for (size_t j(0); j < N - 1 - i; ++ j) {
            swap(matrix[i][j], matrix[N - 1 - j][N - 1 - i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    for (auto& nums : matrix) {
        for (auto& n : nums) {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    rotateMatrix(matrix);
    for (auto& nums : matrix) {
        for (auto& n : nums) {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}
