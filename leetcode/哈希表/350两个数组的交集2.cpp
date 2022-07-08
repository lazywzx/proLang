#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，
则考虑取较小值）。可以不考虑输出结果的顺序。

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/

/* 被骗了，nums2无序
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // 找到两数组的交集
    // 当nums2有序时（手动排序，但这不符合第三条要求）
    sort(nums2.begin(), nums2.end());
    unordered_map<int, int> nums1map;   // 每个数值出现的次数
    for (auto &n : nums1) {
        ++ nums1map[n];
    }

    // 统计交集元素的最小出现次数
    // nums2每次只能读取一个元素，但它是有序的
    int count(0), currn(0);
    vector<int> res;
    size_t i(0);
    while (i != nums2.size()) {
        if (nums1map[nums2[i]]) {
            // 交集
            currn = nums2[i];
            count = 0;
            // 当心溢出
            while (i != nums2.size() && currn == nums2[i]) {
                ++ i;
                ++ count;
            }

            // 选择较小值，向结果中加入这么多个交集值
            res.insert(res.end(), (count < nums1map[currn] ? count : nums1map[currn]), currn);
        }
        else {
            ++ i;
        }
    }

    return res;
}
*/

/*
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // 找到两数组的交集
    // nums1和nums2无序且存在磁盘上
    unordered_map<int, int> nums1map, nums2map;   // 每个数值出现的次数
    for (auto &n : nums1) {
        ++ nums1map[n];
    }

    // nums2实时读取
    for (auto &n : nums2) {
        ++ nums2map[n];
    }

    // 统计交集元素的最小出现次数
    vector<int> res;
    for (auto &p : nums1map) {
        if (nums2map[p.first]) {
            // 交集
            res.insert(res.end(), (p.second < nums2map[p.first] ? p.second : nums2map[p.first]), p.first);
        }
    }

    return res;
}
*/


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // 找到两数组的交集
    // nums2的大小必须已知
    // 更高效的方法是用数组
    const size_t N(1001);
    int map1[N] = {0}, map2[N] = {0};
    for (auto &n : nums1) {
        ++ map1[n];
    }

    for (auto &n : nums2) {
        ++ map2[n];
    }

    // 找最小交集
    vector<int> res;
    for (int i(0); i != N; ++ i) {
        if (map1[i] && map2[i]) {
            // 交集
            res.insert(res.end(), (map1[i] < map2[i] ? map1[i] : map2[i]), i);
        }
    }

    return res;
}
