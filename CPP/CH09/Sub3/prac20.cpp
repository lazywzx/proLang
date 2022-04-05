#include <iostream>
#include <list>
#include <deque>

using namespace std;

// 从list<int>中将偶数拷贝到deque中，奇数拷贝到另一个deque

int main() {
    list<int> li{1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> di1{}, di2{};

    for (auto& i : li) {
        if (i % 2) {
            di1.push_back(i);
        }
        else {
            di2.push_back(i);
        }
    }

    cout << "奇数：" << endl;
    for (auto& i : di1) {
        cout << i << "\t";
    }

    cout << endl << "偶数：" << endl;
    for (auto& i : di2) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}