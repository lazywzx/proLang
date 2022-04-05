#include <vector>
#include <iostream>

using namespace std;

// 访问容器元素，测试空容器

int main() {
    // vector<int> vi{1, 2, 3, 4};
    vector<int> vi{};

    /* at[n] */
    cout << vi.at(0) << endl;

    /* 下标 */
    cout << vi[0] << endl;

    /* front */
    cout << vi.front() << endl;

    /* begin() */
    cout << *(vi.cbegin()) << endl;

    return 0;
}
