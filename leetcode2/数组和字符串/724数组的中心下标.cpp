#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 数组的中心下标
int pivotIndex(vector<int>& nums) {
   // 求整个数组的和
    long sum(0);
    size_t i(0), sz = nums.size();
    for (; i < sz; ++ i) {
        sum += nums[i];
    }

    long zuosum(0); // 左侧数的和
    i = 0;
    int tmp(0);
    for (; i < sz; ++ i) {
        tmp = nums[i];
        if (!(sum - tmp - 2 * zuosum)) {
            // 找到最左侧的中心下标
            return i;
        }
        // 不是中心下标？
        zuosum += tmp;
    }
    return -1;
}


int main() {
    // 将输入的字符串转换成数组
    vector<int> nums;
    nums.reserve(10000);    // 预先分配足够的内存

    string s;
    cout << "输入数组：" << endl;
    getline(cin, s);    // 读入字符串
    // 遍历字符串，提取数组
    for (size_t i = 1; i < s.size() - 1; ++ i) {
        if (isdigit(s[i])) {
            nums.push_back(s[i] - '0');
        }
    }

    auto res = pivotIndex(nums);
    cout << res << endl;

    return 0;
}
