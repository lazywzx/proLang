#include <vector>
#include <iostream>

using namespace std;

// 求数组中连续1的个数的最大值

int findMaxConsecutiveOnes(vector<int>& nums) {
    // 最大连续1的个数
    auto sz(nums.size());
    int sum(0), maxsum(0);
    for (size_t i(0); i != sz; ++ i) {
        if (nums[i]) {
            sum += 1;
        }
        else {
            if (sum > maxsum) {
                maxsum = sum;
            }
            sum = 0;
        }
    }
    // 末尾的1还没有判断
    if (sum > maxsum) {
        return sum;
    }
    return maxsum;
}

int main() {
    vector<int> nums{1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
    auto res = findMaxConsecutiveOnes(nums);

    cout << res << endl;

    return 0;
}
