#include <iostream>
#include <vector>

using namespace std;

// 使用递归找出数列中的最大值

int fmax(vector<int>::const_iterator& b, vector<int>::const_iterator& e) {
    int maxnum = 0, currnum = 0;
    if (b == e) {
        return 0;
    }
    else {
        currnum = *b;
        maxnum = fmax(++ b, e);
        return (currnum > maxnum) ? currnum : maxnum;
    }
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6, 0, 9, 8, 7, 6, 12, 34, 67, 45, 89, 23, 4, 6, 9, 2};
    auto b = vi.cbegin(), e = vi.cend();
    if (b == e) {
        cerr << "No data?!" << endl;
    }
    else {
        cout << "max num: " << fmax(b, e) << endl;
    }

    return 0;
}
