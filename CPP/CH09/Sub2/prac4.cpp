#include <vector>
#include <iostream>

using namespace std;

// ���������еĸ���ֵ

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
        cout << "�ҵ�" << endl;
    }
    else {
        cout << "δ�ҵ�" << endl;
    }

    return 0;
}
