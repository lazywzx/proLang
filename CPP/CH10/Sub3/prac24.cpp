#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

// 在vector<int>中查找第一个值大于给定string长度的值

bool check_size(const string& s, const string::size_type& sz) {
    return s.size() < sz;
}

int main() {
    const vector<int> vi{1, 2, 3, 6, 9, 5, 2, 6, 5, 7, 1, 3, 0, 5, 4, 7, 8, 5, 8, 9};
    const string s("flsfjk");

    auto iter = find_if(vi.cbegin(), vi.cend(), bind(check_size, s, _1));
    cout << *iter << endl;

    return 0;
}

