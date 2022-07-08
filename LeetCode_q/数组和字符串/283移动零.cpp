#include <iostream>
#include <vector>

using namespace std;

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

void moveZeroes(vector<int>& nums) {
    // 原地移动0到末尾
    auto sz(nums.size());
    size_t i(0), j(1);
    
    while (j < sz) {
        if (!nums[i]) {
            if (nums[j]) {
                swap(nums[i ++], nums[j]);
            }
        }
        else {
            ++ i;
        }
        
        ++ j;
    }
}

int main() {
    vector<int> nums{0, 1, 0, 0, 2, 3, 1, 0, 3, 0, 3, 0, 4, 0, 0, 2};
    moveZeroes(nums);
    for (auto& i : nums) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
