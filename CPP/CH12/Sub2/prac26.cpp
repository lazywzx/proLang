#include <iostream>
#include <memory>
#include <string>
#include <new>

using namespace std;

// 使用allocator分配内存

int main() {
    allocator<string> as;
    int n = 3;
    auto p = as.allocate(n), q = p;
    cout << "输入字符串" << endl;
    string s;
    while (cin >> s) {
        as.construct(q, s);
        ++ q;
    }

    auto cnt = q - p;
    for (int i = 0; i != cnt; ++ i) {
        cout << *(p + i) << endl;
    }

    // 销毁
    while (q != p) {
        as.destroy(-- q);
    }
    as.deallocate(p, n);

    return 0;
}
