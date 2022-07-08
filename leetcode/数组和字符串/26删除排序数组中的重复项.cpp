#include <iostream>
#include <vector>

using namespace std;

/*
给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次，
返回删除后数组的新长度。元素的相对顺序应该保持一致。
*/

int removeDuplicates(vector<int>& nums) {
    // 删除排序数组中的重复项
    auto sz(nums.size());
    if (!sz) {
        return 0;
    }

    size_t i(1), j(1);
    while (j < sz) {
        if (nums[i - 1] < nums[j]) {
            swap(nums[i ++], nums[j ++]);
        }
        else {
            ++ j;
        }
    }

    return i;
}

int main() {
    vector<int> nums{0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 5, 5, 7, 9, 12, 12, 13};
    auto res = removeDuplicates(nums);

    for (size_t i(0); i < res; ++ i) {
        cout << nums[i] << "\t";
    }
    cout << endl;

    return 0;
}
