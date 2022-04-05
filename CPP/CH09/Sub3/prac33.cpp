#include <iostream>
#include <vector>

using namespace std;

// 验证插入元素后迭代器指向最后插入的元素

int main() {
    vector<int> li{0, 1, 2, 3, 4, 5};
    auto iter = li.begin();
    while (iter != li.end()) {
        ++ iter;
        li.insert(iter, 42);    // 迭代器失效了
        ++ iter;    // 这个迭代器已失效
    }

    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
