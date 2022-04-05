#include <iostream>
#include <vector>

using namespace std;

// 使用反向迭代器逆序打印vector
// 使用普通迭代器逆序打印vector

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    auto rb = vi.crbegin();
    auto e = vi.cend() - 1;

    cout << "反向迭代器" << endl;
    while (rb != vi.crend()) {
        cout << *rb << "\t";
        ++ rb;
    }

    cout << "\n普通迭代器" << endl;
    while (e != vi.cbegin() - 1) {
        cout << *e << "\t";
        -- e;
    }
    cout << endl;

    return 0;
}