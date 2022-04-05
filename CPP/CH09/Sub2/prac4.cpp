#include <vector>
#include <iostream>

using namespace std;

// 查找容器中的给定值

bool find_int(vector<int>::const_iterator cb, vector<int>::const_iterator ce, const int& i) {
    for(; cb != ce; ++ cb) {
        if (*cb == i) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6};
    int i = 8;
    if (find_int(vi.cbegin(), vi.cend(), i)) {
        cout << "找到" << endl;
    }
    else {
        cout << "未找到" << endl;
    }

    return 0;
}
