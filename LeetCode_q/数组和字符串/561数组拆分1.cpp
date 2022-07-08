#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 给定2n长度数组，两两配对，使数对中最小值之和最大

int arrayPairSum(vector<int>& nums) {
    // 给定2n长度数组，两两配对，使数对中最小值之和最大
    // 数组中至少有2个元素
    // 先排序
    sort(nums.begin(), nums.end());
    int sum(0);
    // 从第一个元素开始，隔一个元素取值
    for (size_t i(0); i != nums.size(); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    vector<int> nums{1, 23, 88, 50, 2, 6, 7, 8, 3, 4, 5, 9, 0, 12, 33, 2, 78, 5, 44, 98, 31, 66};
    auto res = arrayPairSum(nums);
    cout << res << endl;

    return 0;
}
