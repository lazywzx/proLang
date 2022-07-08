#include <iostream>
#include <vector>

using namespace std;

// 移除数组中指定元素

int removeElement(vector<int>& nums, int val) {
    // 原地移除nums中的val，返回结果长度
    // 不用管超出新长度的部分
    // 顺序可变
    auto sz(nums.size());
    if (!sz) {
        return 0;
    }

    size_t i(0), j(0);
    while (i < sz) {
        if (nums[i] == val) {
            ++ i;
        }
        else {
            swap(nums[i ++], nums[j ++]);
        }
    }
    return j;
}

int main() {
    vector<int> nums{1, 2, 3, 5, 1, 2, 6, 9, 0, 6, 3, 4};
    auto res = removeElement(nums, 2);
    for (auto i(0); i != res; ++ i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
