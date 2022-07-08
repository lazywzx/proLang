#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
你可以按 任意顺序 返回答案。
*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    // 返回前k多的元素
    sort(nums.begin(), nums.end());

    // 自定义map的key排序规则，使其由大到小排序
    // 自定义比较器在本地编译器正常，但在leetcode编译失败
    struct CmpByKeyValue {
        bool operator()(const size_t& a, const size_t& b) {
            return a > b;
        }
    };
    
    // 使用greater<key_type>对key进行升序排序
    map<size_t, vector<int>, greater<size_t>> numsmap;
    size_t i(0), j(0);
    while (j != nums.size()) {
        while (j != nums.size() && nums[j] == nums[i]) {
            ++ j;
        }
        // 出现次数作为key，对应元素作为value，有序哈希map
        numsmap[j - i].emplace_back(nums[i]);
        i = j;
    }

    // 取有序hash前k个key对应的元素
    // 默认由小到大排序，结果为前K低频
    vector<int> res;
    for (auto &p : numsmap) {
        if (!k) {
            return res;
        }

        res.insert(res.end(), p.second.cbegin(), p.second.cend());
        k -= p.second.size();
    }

    return res;
}


int main() {
    vector<int> nums = {1, 1, 1, 1, 2, 3, 3, 2, 2, 4, 3, 5};
    int k = 3;

    auto res(topKFrequent(nums, k));

    for (auto &n : res) {
        cout << n << endl;
    }

    return 0;
}

