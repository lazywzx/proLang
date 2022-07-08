#include <iostream>
#include <vector>

using namespace std;

// 返回杨辉三角指定行
// 计算公式
// C(n, m) = n! / [m!(n - m)!]

/*
vector<int> getRow(int rowIndex) {
    // 返回杨辉三角指定行
    // 计算公式: C(n, m) = n! / [m!(n - m)!]
    vector<int> res(rowIndex + 1, 1);
    if (rowIndex > 0) {
        res[1] = rowIndex;
        res[rowIndex - 1] = rowIndex;

        unsigned long long tmp_n(1), tmp_m(1);
        int index_cp, i_cp, diff_nm;
        for (size_t i(2); i < rowIndex - 1; ++ i) {
            // 计算阶乘
            index_cp = rowIndex;
            i_cp = i;
            diff_nm = index_cp - i_cp;
            
            // 较大的子阶乘就不用算了
            if (i_cp > index_cp / 2) {
                while (diff_nm > 1) {
                    // 计算较小的那个阶乘
                    tmp_m *= diff_nm --;
                    // 较大的，算一部分阶乘
                    tmp_n *= index_cp --;
                    // 每算一步，约掉一个公约数
                    if (tmp_m % 2 == 0 && tmp_n % 2 == 0) {
                        tmp_m /= 2;
                        tmp_n /= 2;
                    }
                }
                // 较大的还差一步
                tmp_n *= index_cp;
            }
            else {
                while (i_cp > 1) {
                    tmp_m *= i_cp --;
                    tmp_n *= index_cp --;
                    if (tmp_m % 2 == 0 && tmp_n % 2 == 0) {
                        tmp_m /= 2;
                        tmp_n /= 2;
                    }
                }
                tmp_n *= index_cp;
            }

            res[i] = tmp_n / tmp_m;
            // 记得归为啊
            tmp_n = 1;
            tmp_m = 1;
        }
    }

    return res;
}
*/

vector<int> getRow(int rowIndex) {
    // 迭代计算方法
    vector<int> res(rowIndex + 1, 1);
    res.reserve(rowIndex + 1);

    if (rowIndex > 1) {
        // 从第三行开始迭代计算
        for (size_t i(2); i <= rowIndex; ++ i) {
            for (size_t j(i - 1); j > 0; -- j) {
                res[j] = res[j - 1] + res[j];   // 从后向前累加
            }
        }
    }

    return res;
}


int main() {
    int rowIndex(30);

    auto res = getRow(rowIndex);

    for (auto& i : res) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
