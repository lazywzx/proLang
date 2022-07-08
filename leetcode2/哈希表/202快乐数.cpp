#include <unordered_set>

using namespace std;

/*
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/


/* 哈希集合方法，效率不高
bool isHappy(int n) {
    // 判断n是否为快乐数
    // 对于每个结果，检查其是否之前出现过，否则继续，是则非快乐数，直到结果为1
    unordered_set<int> res_set;
    int tmp(n);
    while (n != 1 && res_set.emplace(n).second) {
        // 该数没出现过
        tmp = n;
        n = 0;
        while (tmp) {
            n += (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }
    }

    return (n == 1 ? true : false);
}
*/


int next_n(int n) {
    int sum(0);
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}


bool isHappy(int n) {
    // 判断n是否为快乐数
    // 对于每个结果，检查其是否之前出现过，否则继续，是则非快乐数，直到结果为1
    // 快慢指针法，效率高
    int fast(n), slow(n);
    do {
        slow = next_n(slow);
        fast = next_n(next_n(fast));
    } while (fast != slow);

    return (fast == 1 ? true : false);
}
