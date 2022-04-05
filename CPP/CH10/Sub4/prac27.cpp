#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// 将vector中不重复元素拷贝到空list
// 使用unique_copy

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 2, 1, 3, 6, 9, 8, 0, 4, 5, 6, 2, 3, 7, 6, 8, 9, 3, 4, 1, 2, 6, 8};
    list<int> li;

    sort(vi.begin(), vi.end());
    unique_copy(vi.begin(), vi.end(), back_inserter(li));

    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}