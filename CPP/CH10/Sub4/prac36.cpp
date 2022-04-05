#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 使用find在list<int>中查找最后一个0

int main() {
    list<int> li{1, 2, 3, 4, 5, 6, 0, 1, 3, 4, 0, 5, 8, 9, 0, 3, 4, 6};
    auto rzero = find(li.crbegin(), li.crend(), 0);
    auto common_iter = -- rzero.base();
    while (common_iter != li.cend()) {
        cout << *common_iter << "\t";
        ++ common_iter;
    }
    cout << endl;

    return 0;
}