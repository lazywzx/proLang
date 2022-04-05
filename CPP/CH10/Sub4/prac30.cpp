#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

// 使用流迭代器，sort、copy从标准输入读取整数序列
// 将排序结果输出

int main() {
    cout << "输入整数序列" << endl;

    istream_iterator<int> ii(cin), eof;
    ostream_iterator<int> oi(cout, " ");

    vector<int> vi(ii, eof);
    sort(vi.begin(), vi.end());

    unique_copy(vi.cbegin(), vi.cend(), oi);

    return 0;
}
