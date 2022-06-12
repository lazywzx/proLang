#include <iostream>
#include <vector>

using namespace std;

// 输入有序数组，求两个元素之和等于目标值的元素下标

vector<int> twoSum(vector<int>& numbers, int target) {
    // 有序数组中两数之和等于目标值的两个下标
    // 有且仅有一个答案
    vector<int> res{1, 2};
    if (numbers.size() == 2) {
        // 处理特殊情况
        return res;
    }
    
    size_t i(0), j(numbers.size() - 1);
    int sum(0);
    while (true) {
        sum = numbers[i] + numbers[j];
        if (sum == target) {
            res[0] = i + 1;
            res[1] = j + 1;
            return res;
        }
        else if (sum < target) {
            ++ i;
        }
        else {
            -- j;
        }
    }
}

int main() {
    vector<int> nums{2, 3, 4};
    auto res = twoSum(nums, 6);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
