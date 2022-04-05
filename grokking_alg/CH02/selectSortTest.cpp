#include <iostream>
#include <list>

using namespace std;

// 选择排序算法思想演示

list<int>::const_iterator findSmallest(list<int>& li) {
    /* 返回给定链表中最小值的迭代器 */
    auto min_iter = li.cbegin(), iter = li.cbegin();
    ++ iter;
    for (; iter != li.cend(); ++ iter) {
        if (*iter < *min_iter) {
            min_iter = iter;
        }
    }

    return min_iter;
}

list<int> selectSort(list<int> li) {
    /* 选择排序算法 */
    list<int> result;
    auto sz = li.size();
    for (int i = 0; i != sz; ++ i) {
        auto iter = findSmallest(li);   // 引用传值，否则迭代器指向的是其拷贝
        result.push_back(*iter);
        li.erase(iter); // 删除当前最小值
    }

    return result;
}

int main() {
    list<int> li{5, 3, 0, 8, 9, 5, 6, 8, 1, 3, 5, 6, 7, 2, 3, 9, 8};
    auto result = selectSort(li);
    // 打印结果
    for (auto& i : result) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
