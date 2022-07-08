#include <vector>

using namespace std;

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。
要求O(N)时间，O(1)空间
*/

int singleNumber(vector<int>& nums) {
    // 寻找数组中只出现一次的数字，其他数字均出现两次
    // 要求O(N)时间、O(1)空间
    // 利用异或运算技巧：自己与自己异或结果为0，所有元素异或结果为单独出现的那个元素值
    int res(0);
    for (auto &n : nums) {
        res ^= n;
    }

    return res;
}

