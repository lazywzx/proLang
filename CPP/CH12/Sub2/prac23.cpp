#include <iostream>
#include <new>
#include <memory>
#include <cstring>
#include <string>

using namespace std;

// 连接两个字符串字面值常量，保存在动态分配的char数组中
// 连接两个标准库string

int main() {
    auto s1l = strlen("line1"), s2l = strlen("line2");
    unique_ptr<char[]> up(new char[s1l + s2l]());   // 必须执行值初始化，否则未定义
    strcat(up.get(), "line1");
    strcat(up.get(), "line2");

    // 打印
    for (int i = 0; i != s1l + s2l; ++ i) {
        cout << up[i];
    }
    cout << endl;

    string s1("string1"), s2("string2");
    auto ls1 = s1.size(), ls2 = s2.size();
    unique_ptr<char[]> sp(new char[ls1 + ls2]());
    strcat(sp.get(), (s1 + s2).c_str());

    for (int i = 0; i != ls1 + ls2; ++ i) {
        cout << sp[i];
    }
    cout << endl;

    return 0;
}
