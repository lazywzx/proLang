#include <vector>
#include <unordered_set>

using namespace std;

/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // 返回两个数组的交集
    unordered_set<int> nums1_set, res_set;
    for (auto &n : nums1) {
        nums1_set.emplace(n);
    }

    for (auto &n : nums2) {
        if (nums1_set.find(n) != nums1_set.end()) {
            // 交集元素
            res_set.emplace(n);
        }
    }

    return vector<int>(res_set.cbegin(), res_set.cend());
}
*/


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // 返回两个数组的交集
    // 由vector直接构造生成set
    unordered_set<int> nums1_set(nums1.cbegin(), nums1.cend()), nums2_set(nums2.cbegin(), nums2.cend());
    vector<int> res;
    for (auto &n : nums1_set) {
        if (nums2_set.find(n) != nums2_set.cend()) {
            res.emplace_back(n);
        }
    }

    return res;
}
