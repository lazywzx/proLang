#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

// 读入字符串，存入动态分配的字符数组中

int main() {
    cout << "输入字符串" << endl;
    int cnt = 1;
    char c;
    unique_ptr<char[]> sp(new char[1]{'\0'});

    while (cin >> c) {
        ++ cnt;
        unique_ptr<char[]> tmp_p(new char[cnt]{c});
        strcat(tmp_p.get(), sp.get());
        sp.reset(tmp_p.release());  // 转移控制权
    }

    // 按照逆序存储
    // 输出
    for (int i = cnt; i != 0; -- i) {
        cout << sp[i - 1];
    }
    cout << endl;

    return 0;
}
