#include <vector>
#include <memory.h>

using namespace std;

/*
请你判断一个 9 x 9 的数独是否有效。
只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/

/*
bool isValidSudoku(vector<vector<char>>& board) {
    // 判断已填入数字是否有效
    // 检查行
    for (size_t i(0); i != 9; ++ i) {
        bool numset[12] = {false};
        for (size_t j(0); j != 9; ++ j) {
            size_t index(board[i][j] - '.');
            if (index) {
                // 不是'.'
                if (numset[index]) {
                    // 已经存在，不满足条件一
                    return false;
                }
                else {
                    numset[index] = true;
                }
            }
        }
    }

    // 检查列
    for (size_t j(0); j != 9; ++ j) {
        bool numset[12] = {false};
        for (size_t i(0); i != 9; ++ i) {
            size_t index(board[i][j] - '.');
            if (index) {
                if (numset[index]) {
                    // 已经存在，不满足条件二
                    return false;
                }
                else {
                    numset[index] = true;
                }
            }
        }
    }

    // 检查宫
    for (size_t k(0); k != 9; ++ k) {
        bool numset[12] = {false};
        size_t begi(k / 3 * 3); // 对于每个宫，行开始的位置
        size_t begj(k % 3 * 3); // 对于每个宫，列开始的位置
        for (size_t i(begi); i != begi + 3; ++ i) {
            for (size_t j(begj); j != begj + 3; ++ j) {
                size_t index(board[i][j] - '.');
                if (index) {
                    if (numset[index]) {
                        // 已经存在，不满足条件三
                        return false;
                    }
                    else {
                        numset[index] = true;
                    }
                }
            }
        }
    }

    return true;
}
*/


bool isValidSudoku(vector<vector<char>>& board) {
    // 判断已填入数字是否有效
    // 同时检查行列宫
    bool row[9][9], col[9][9], palce[3][3][9];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(palce, false, sizeof(palce));

    for (size_t i(0); i != 9; ++ i) {
        for (size_t j(0); j != 9; ++ j) {
            // 对每个元素判断其所在行、列、宫是否已经出现过
            if (board[i][j] != '.') {
                size_t index(board[i][j] - '1');
                if (row[i][index]) return false;
                else row[i][index] = true;

                if (col[index][j]) return false;
                else col[index][j] = true;

                if (palce[i / 3][j / 3][index]) return false;
                else palce[i / 3][j / 3][index] = true;
            }
        }
    }

    return true;
}
