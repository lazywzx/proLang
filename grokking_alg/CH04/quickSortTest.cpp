#include <iostream>
#include <vector>

using namespace std;

// 快速排序算法思想演示
// 递归 D&C

vector<int> quickSort(vector<int> vi) {
    if (vi.size() < 2) {
        return vi;  // 基线条件
    }
    else {
        auto pivot = vi[0];  //  选择基准值
        vector<int> smaller, bigger;
        for (auto iter = vi.cbegin() + 1; iter != vi.cend(); ++ iter) {
            if (*iter <= pivot) {
                smaller.push_back(*iter);   // 小于基准值的元素
            }
            else {
                bigger.push_back(*iter);    // 大于基准值的元素
            }
        }
        // 递归
        auto lesser = quickSort(smaller);
        auto greater = quickSort(bigger);
        lesser.push_back(pivot);    // 小于基准值 基准值 大于基准值排序
        for (auto iter = greater.cbegin(); iter != greater.cend(); ++ iter) {
            lesser.push_back(*iter);
        }
        return lesser;
    }
}

int main() {
    vector<int> vi{5, 3, 0, 8, 9, 5, 6, 8, 1, 3, 5, 6, 7, 2, 3, 9, 8};
    auto result = quickSort(vi);

    // 打印结果
    for (auto& i : result) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
