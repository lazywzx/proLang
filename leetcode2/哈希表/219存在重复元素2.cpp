#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
*/

/*
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // 是否存在距离小于等于k的两个相等元素（必须是不同的两个）
    if (!k) {
        return false;
    }

    unordered_map<int, size_t> mapn;
    for (size_t i(0); i != nums.size(); ++ i) {
        if (mapn.find(nums[i]) != mapn.end() && i - mapn[nums[i]] <= k) {
            // 已经存在，判断索引差
            return true;
        }
        // 更新该值的最近索引
        mapn[nums[i]] = i;
    }

    return false;
}
*/


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // 是否存在距离小于等于k的两个相等元素（必须是不同的两个）
    // 滑动窗口内遍历
    // 时间O(k*N)超出限制
    if (!k) {
        return false;
    }

    for (int i(0); i != nums.size(); ++ i) {
        for (int j(max(0, i - k)); j < i; ++ j) {
            // 在窗口内搜索
            if (nums[j] == nums[i]) {
                return true;
            }
        }
    }

    return false;
}


