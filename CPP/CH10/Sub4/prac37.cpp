#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 将一个10元素的vector中的3-7位置元素按逆序拷贝到list
// 不是排序，只是逆序拷贝

int main() {
    vector<int> vi{2, 1, 3, 4, 8, 5, 7, 6, 9, 0};
    list<int> li(5, 0);
    copy(vi.cbegin() + 3, vi.cbegin() + 8, li.rbegin());
    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
