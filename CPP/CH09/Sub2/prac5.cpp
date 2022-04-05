#include <iostream>
#include <vector>

using namespace std;

// Ѱ�������еĸ���ֵ�����ص�����

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
        cout << "�ҵ���ֵΪ��" << *ci << endl;
    }
    else {
        cout << "δ�ҵ�" << endl;
    }

    return 0;
}
