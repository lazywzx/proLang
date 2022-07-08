#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 合并有重叠区域的区间
// 先按区间左值升序排序

vector<vector<int>> quickSort(vector<vector<int>>& vi) {
    // 对二维数组按照第二维度的第一个元素升序排序
    // 快速排序算法
    if (vi.size() < 2) {
        return vi;  // 基线条件
    }
    else {
        auto pivot = vi[0];  //  选择基准值
        vector<vector<int>> smaller, bigger;
        for (auto iter = vi.cbegin() + 1; iter != vi.cend(); ++ iter) {
            if ((*iter)[0] <= pivot[0]) {
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

vector<vector<int>> mergeInterval(vector<vector<int>>& intervals) {
    // 合并数组区间
    // 先对区间排序
    // 使用内置的sort算法
    // auto res = quickSort(nums);
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merge_nums;
    // merge_nums.reserve(10000);  // 预先分配内存
    size_t i(0), sz(intervals.size()), c_f_index(0);
    int max_sec(intervals[0][1]), tmp;

    for (; i < sz; ++ i) {
        // 遍历整个数组

        /* 假如后续有连续的K个区间，其左值都比当前右值小
            那么只要在这K个区间中寻找最大右值即可
        */
        // 寻找最大右值
        if (max_sec >= intervals[i][0]) {
            tmp = intervals[i][1];
            if (max_sec < tmp) {
                max_sec = tmp;
            }
        }
        else {
            merge_nums.push_back({intervals[c_f_index][0], max_sec});
            // 下一个区间
            c_f_index = i;
            max_sec = intervals[i][1];
        }
    }

    merge_nums.push_back({intervals[c_f_index][0], max_sec});

    return merge_nums;
}

int main() {
    // 测试合并区间
    vector<vector<int>> vi{{5, 8}, {3, 6}, {0, 2}, {8, 9}, {5, 6}, {20, 22}, {22, 25}, {8, 12}, {1, 3}, {0, 5}, {6, 7}, {2, 3}, {9, 12}, {13, 18}};
    auto res = mergeInterval(vi);
    // 打印结果
    for (auto& i : res) {
        cout << "[" << i[0] << ", " << i[1] << "]" << "\n";
    }
    cout << endl;

    return 0;
}

