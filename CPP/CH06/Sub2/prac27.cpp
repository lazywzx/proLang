#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

// 可变数量形参

void sum(initializer_list<int> lst) {
    int s = 0;
    for (const auto &n : lst) {
        s += n;
    }
    cout << "参数列表的和为：" << s << endl;
}

int main() {
    sum({1, 2, 3, 4, 5});

    return 0;
}
