#include <iostream>
#include <vector>

using namespace std;

// 寻找容器中的给定值，返回迭代器

vector<int>::const_iterator find_val(vector<int>::const_iterator cb, vector<int>::const_iterator ce, const int& val) {
    for (; cb != ce; ++ cb) {
        if (*cb == val) {
            break;
        }
    }
    return cb;
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6};
    int val = 8;

    vector<int>::const_iterator ci = find_val(vi.cbegin(), vi.cend(), val);
    if (ci != vi.cend()) {
        cout << "找到，值为：" << *ci << endl;
    }
    else {
        cout << "未找到" << endl;
    }

    return 0;
}
