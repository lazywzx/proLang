#include <unordered_map>
#include <vector>

using namespace std;

/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，
请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/


int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    // 四数相加为0的索引组合个数
    // n1+n2 = -(n3+n4)
    unordered_map<int, int> map12;

    for (auto &n1 : nums1) {
        for (auto &n2 : nums2) {
            // 不存在就创建并初始化为0后加1，存在就直接递增
            ++ map12[-(n1 + n2)];
        }
    }

    int count(0);
    // 每当n3+n4=-(n1+n2)时，就累加map12中记录的组合数
    for (auto &n3 : nums3) {
        for (auto &n4 : nums4) {
            auto iter = map12.find(n3 + n4);
            if (iter != map12.end()) {
                // 存在相反数
                count += iter->second;
            }
        }
    }

    return count;
}
