#include <iostream>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

// 比较两数组是否相等，比较两容器是否相等
int iarr1[5] = {1, 2, 3, 4, 5};
int iarr2[5] = {1, 2, 3, 4, 5};
int iarr3[5] = {1, 2, 2, 4, 5};

vector<int> ivec1 = {1, 2, 3, 4, 5};
vector<int> ivec2 = {1, 2, 3, 4, 5};
vector<int> ivec3 = {1, 2, 2, 4, 5};

int main() {
    cout << "数组：" << endl;
    auto b1 = begin(iarr1), e1 = end(iarr1);
    auto b2 = begin(iarr2), e2 = end(iarr2);
    auto b3 = begin(iarr3), e3 = end(iarr3);

    bool flag = false;
    if ((e1 - b1) == (e2 - b2)) {
        flag = true;
        for (; b1 != e1; ++ b1, ++ b2) {
            if (*b1 != *b2) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "iarr1 == iarr2" << endl;
    }
    else {
        cout << "iarr1 != iarr2" << endl;
    }

    flag = false;
    if ((e1 - b1) == (e3 - b3)) {
        flag = true;
        for (; b1 != e1; ++ b1, ++ b3) {
            if (*b1 != *b3) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "iarr1 == iarr3" << endl;
    }
    else {
        cout << "iarr1 != iarr3" << endl;
    }

    flag = false;
    if ((e2 - b2) == (e3 - b3)) {
        flag = true;
        for (; b2 != e2; ++ b2, ++ b3) {
            if (*b2 != *b3) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "iarr2 == iarr3" << endl;
    }
    else {
        cout << "iarr2 != iarr3" << endl;
    }

    cout << "容器：" << endl;
    if (ivec1 == ivec2) {
        cout << "ivec1 == ivec2" << endl;
    }
    else {
        cout << "ivec1 != ivec2" << endl;
    }
    if (ivec1 == ivec3) {
        cout << "ivec1 == ivec3" << endl;
    }
    else {
        cout << "ivec1 != ivec3" << endl;
    }
    if (ivec2 == ivec3) {
        cout << "ivec2 == ivec3" << endl;
    }
    else {
        cout << "ivec2 != ivec3" << endl;
    }

    return 0;
}
