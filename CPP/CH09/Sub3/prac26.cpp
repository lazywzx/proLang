#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 将数组拷贝到vector和list中，使用单迭代器的erase分别删除偶数和奇数

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> iv{};
    list<int> il{};
    for (auto& i : ia) {
        iv.push_back(i);
        il.push_back(i);
    }

    for (auto vb = iv.cbegin(); vb != iv.cend();) {
        if (!(*vb % 2)) {
            vb = iv.erase(vb);
        }
        else {
            ++ vb;
        }
    }

    for (auto lb = il.cbegin(); lb != il.cend();) {
        if (*lb % 2) {
            lb = il.erase(lb);
        }
        else {
            ++ lb;
        }
    }

    cout << "vector: " << endl;
    for (auto& i : iv) {
        cout << i << "\t";
    }
    
    cout << endl << "list: " << endl;
    for (auto& i : il) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}