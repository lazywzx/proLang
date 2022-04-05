#include <iostream>
#include <string>
#include <map>

using namespace std;

// 使用multimap保存作者及书名，使用find查找指定元素并用erase删除

int main() {
    multimap<string, string> authors{
        {"wangzixu", "C++"},
        {"zhang", "Python"},
        {"wangzixu", "Linux"}
    };

    for(auto& a : authors) {
        cout << a.first << ": " << a.second << endl;
    }

    /* 查找并删除 */
    string dele_name("li");
    if (authors.find(dele_name) != authors.end()) {
        authors.erase(dele_name);
        cout << "删除成功" << endl;
    }
    else {
        cerr << "不在容器中" << endl;
    }

    /* 输出结果 */
    for(auto& a : authors) {
        cout << a.first << ": " << a.second << endl;
    }

    return 0;
}