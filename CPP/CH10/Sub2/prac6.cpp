#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用fill_n

int main() {
    vector<int> li(10, 1);
    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    fill_n(li.begin(), li.size(), 0);
    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
