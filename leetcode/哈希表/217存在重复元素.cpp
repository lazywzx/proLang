#include <vector>
#include <unordered_set>

using namespace std;

/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；
如果数组中每个元素互不相同，返回 false 。
*/


bool containsDuplicate(vector<int>& nums) {
    // 判断数组中是否存在重复元素
    unordered_set<int> nums_set;
    for (auto &n : nums) {
        if (!nums_set.emplace(n).second) {
            return true;
        }
    }

    return false;
}
