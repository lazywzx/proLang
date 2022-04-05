#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 跨类型初始化容器

int main() {
    /* list<int>初始化vector<double> */
    list<int> li{1, 2, 3, 4, 5};
    vector<double> vd(li.begin(), li.end());

    /* vector<int>初始化vector<double> */
    vector<int> vi{1, 2, 3, 4, 5};
    vector<double> vd2(vi.begin(), vi.end());

    for (auto &i : vd) {
        cout << i << "\t";
    }
    cout << endl;

    for (auto &i : vd2) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
