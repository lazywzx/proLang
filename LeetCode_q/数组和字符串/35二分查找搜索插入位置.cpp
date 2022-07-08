#include <iostream>
#include <vector>

using namespace std;

// 使用二分查找找到给定元素的索引
// 如果不存在，返回按顺序插入的位置
// 不要上来就二分查找，可以先判断首尾元素

int searchInsert(vector<int>& nums, int target) {
    // 判断首尾元素
    size_t sz = nums.size();
    if (target <= nums[0]) {
        return 0;
    }

    if (target > nums[sz - 1]) {
        return sz;
    }

    // 在1到sz-1之间二分查找
    size_t lp(1), rp(sz - 1), mid(sz / 2);
    int tmp = nums[mid];
    while (lp <= rp) {
        if (target == tmp) {
            return mid;
        }
        
        if (target < tmp) {
            rp = mid - 1;
        }
        else {
            lp = mid + 1;
        }
        mid = (lp + rp) / 2;
        tmp = nums[mid];
    }

    // 没找到
    return lp;
}

int main() {
    vector<int> nums{1, 2, 4, 5, 7, 9, 23, 45, 66, 89, 95};
    int target(24);
    auto res = searchInsert(nums, target);

    cout << res << endl;

    return 0;
}
