#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 二分查找算法

vector<string>::const_iterator binarySearch(const vector<string>& vs, const string& word) {
    /* 传入的容器必须有序 */
    auto b = vs.cbegin(), e = vs.cend();
    while (b < e) {
        auto mid = b + (e - b) / 2;
        if (*mid == word)
            return mid;
        
        if (*mid <= word)
            b = mid + 1;    // 右半区间
        else
            e = mid - 1;    // 左半区间
    }
    // 没找到返回尾后迭代器
    return vs.cend();
}

int main() {
    vector<string> vs{"21S", "HIT", "dianzi", "gongcheng", "hebei", "kexue", "tangshan", "wang", "xi", "xinxi", "xu", "xueyuan", "yu", "zi"};
    auto iter = binarySearch(vs, "wan");
    if (iter != vs.cend()) {
        cout << "找到，位置：" << iter - vs.cbegin() << endl;
    }
    else {
        cout << "没找到" << endl;
    }

    return 0;
}

