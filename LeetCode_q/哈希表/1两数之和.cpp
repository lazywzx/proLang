#include <vector>
#include <unordered_map>

using namespace std;

/*
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/


vector<int> twoSum(vector<int>& nums, int target) {
    // 找出和为target的那两个数的索引
    // 使用multimap，效率极低
    // 基于条件：target = 2a，nums中仅有2个a；target = a+b，nums中仅有1个a和1个b
    unordered_map<int, int> nums_map;
    int diff(0);
    for (int i(0); i != nums.size(); ++ i) {
        // 创建map的同时检查
        diff = target - nums[i];
        auto diff_iter(nums_map.find(diff));
        if (diff_iter != nums_map.end()) {
            return {i, diff_iter->second};
        }

        auto iter(nums_map.insert({nums[i], i}));

        if (!iter.second && diff == nums[i]) {
            // 如果插入失败，说明nums中有两个nums[i]
            // 如果此时target == 2 * diff，结束
            return {i, diff_iter->second};
        }
    }

    return {};
}

