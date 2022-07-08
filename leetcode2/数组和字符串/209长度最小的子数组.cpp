#include <iostream>
#include <vector>

using namespace std;

// 长度最小的子数组
// 双指针滑动窗口
/*
    给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
    如果不存在符合条件的子数组，返回 0 。
*/

/*
int minSubArrayLen(int target, vector<int>& nums) {
    // 寻找满足和>=target的最短子数组
    // 求数组前缀和
    auto sz(nums.size());
    for (size_t i(1); i != sz; ++ i) {
        nums[i] += nums[i - 1];
    }

    // 如果最大的比target小，不符合条件
    if (nums[sz - 1] < target) {
        return 0;
    }

    int i(0), j(-1);
    int minlenght(sz);
    while (i < sz) {
        // 找到大于等于target的子数组的右端
        if (j < 0) {
            while (i < sz && nums[i] < target) {
                ++ i;
            }
            j = 0;
        }
        else {
            while (i < sz && (nums[i] - nums[j]) < target) {
                ++ i;
            }
        }

        if (i == sz) {
            // 遍历完成
            break;
        }

        // 从左端不断缩小数组长度，直到<target
        while ((nums[i] - nums[j]) >= target) {
            ++ j;
        }

        // 更新最小长度
        if ((i - j + 1) < minlenght) {
            minlenght = i - j + 1;
        }
    }

    return minlenght;
}
*/

int minSubArrayLen(int target, vector<int>& nums) {
    // 滑动窗口解法，比前缀和好
    auto sz(nums.size());
    size_t i(0), j(0), minlenght(sz + 1);   // 把最小长度初始化为sz + 1，如果最终没有减小的话，说明不满足条件
    int sum(0);
    
    while (i < sz) {
        // 展开窗口
        while (i < sz && sum < target) {
            sum += nums[i ++];  // sum只是当前窗口中的元素的和
            // i指向窗口的右一个元素
        }
        if (i == sz && sum < target) {
            break;      // i==sz了还没有>=target，不用收缩窗口了
        }

        // 收缩窗口
        while (j < i && sum >= target) {
            sum -= nums[j ++];  // j指向窗口的右一个元素
        }
        if (j == i) {
            return 1;   // 如果是j==i导致的退出，说明最小长度为1
        }

        // 更新最小长度
        if ((i - j + 1) < minlenght) {
            minlenght = i - j + 1;
        }
    }

    return minlenght == sz + 1 ? 0 : minlenght;     // 如果没有变小过，说明不符合条件
}

int main() {
    vector<int> nums{1, 4, 6, 2, 45, 0, 90, 22, 31, 3, 9, 8, 5, 0, 3, 2, 5, 6, 7, 7, 7, 3, 2, 12, 32, 63, 22, 3, 18};
    int target(250);

    auto res = minSubArrayLen(target, nums);
    cout << res << endl;

    return 0;
}
