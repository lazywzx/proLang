#include <iostream>
#include <vector>

using namespace std;

// 沿着对角线遍历矩阵

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // 沿着对角线遍历矩阵
    auto M(mat.size());
    vector<int> res;
    if (!M) {
        return res;
    }

    auto N(mat[0].size());
    res.reserve(M * N); // 分配好内存空间

    // 遍历矩阵
    size_t i(0), j(0);
    // 先判断特殊情况
    // 单行
    if (M == 1) {
        res = mat[0];
        return res;
    }
    else if (N == 1) {
        for (; i != M; ++ i) {
            res.push_back(mat[i][0]);
        }
        return res;
    }

    bool direc(true);   // 向右上角走是true

    while (i < M && j < N) {
        res.push_back(mat[i][j]);
        // 判断在哪里碰壁了
        if (i == 0 && j == N - 1) {
            ++ i;
            if (i == M) {
                break;
            }
            direc = !direc;
            res.push_back(mat[i][j]);
        }
        else if (i == M - 1 && j == 0) {
            ++ j;
            if (j == N) {
                break;
            }
            direc = !direc;
            res.push_back(mat[i][j]);
        }
        else if (i == 0 || i == M - 1) {
            ++ j;
            if (j == N) {
                break;
            }
            direc = !direc;
            res.push_back(mat[i][j]);
        }
        else if (j == 0 || j == N - 1) {
            ++ i;
            if (i == M) {
                break;
            }
            direc = !direc;
            res.push_back(mat[i][j]);
        }

        // 不断在对角线上走
        if (direc) {
            ++ j;
            -- i;
        }
        else {
            -- j;
            ++ i;
        }
    }
    
    return res;
}

int main() {
    vector<vector<int>> matrix{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    vector<vector<int>> matrix2{{1, 2, 3, 4, 5, 6}};
    vector<vector<int>> matrix3{{1}, {6}, {11}, {16}, {21}};

    for (auto& nums : matrix3) {
        for (auto& n : nums) {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    auto res = findDiagonalOrder(matrix3);
    for (auto& n : res) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
