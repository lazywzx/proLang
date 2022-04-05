#include <iostream>
#include <vector>
#include <iterator>
#include <deque>

using namespace std;

// 将vector拷贝到其他容器中
// 使用inserter front_inserter back_inserter，观察插入顺序

void print_v(const deque<int>& v) {
    for (auto& i : v) {
        cout << i << "\t";
    }
    cout << endl;
}

int main() {
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> ins, fro, bac;

    copy(vi.cbegin(), vi.cend(), inserter(ins, ins.begin()));
    print_v(ins);

    copy(vi.cbegin(), vi.cend(), back_inserter(bac));
    print_v(bac);

    copy(vi.cbegin(), vi.cend(), front_inserter(fro));
    print_v(fro);

    return 0;
}
