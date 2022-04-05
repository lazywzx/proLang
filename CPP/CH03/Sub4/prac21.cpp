#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// 使用迭代器验证vector对象
int main() {
    vector<int> v1; // 一个空的int型容器
    cout << "v1容量：" << v1.size() << endl;
    cout << "v1内容：" << endl;
    for (auto it = v1.cbegin(); it != v1.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;
    
    vector<int> v2(10); // 10个int型元素，值为0
    cout << "v2容量：" << v2.size() << endl;
    cout << "v2内容：" << endl;
    for (auto it = v2.cbegin(); it != v2.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;

    vector<int> v3(10, 42); // 10个int型元素，值为42
    cout << "v3容量：" << v3.size() << endl;
    cout << "v3内容：" << endl;
    for (auto it = v3.cbegin(); it != v3.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;

    vector<int> v4{10}; // 1个int型元素，值为10
    cout << "v4容量：" << v4.size() << endl;
    cout << "v4内容：" << endl;
    for (auto it = v4.cbegin(); it != v4.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;

    vector<int> v5{10, 42}; // 2个int型元素，值为10和42
    cout << "v5容量：" << v5.size() << endl;
    cout << "v5内容：" << endl;
    for (auto it = v5.cbegin(); it != v5.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;

    vector<string> v6{10};  // 10个空string字符串
    cout << "v6容量：" << v6.size() << endl;
    cout << "v6内容：" << endl;
    for (auto it = v6.cbegin(); it != v6.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;

    vector<string> v7{10, "hi"};    // 10个字符串，值为"hi"
    cout << "v7容量：" << v7.size() << endl;
    cout << "v7内容：" << endl;
    for (auto it = v7.cbegin(); it != v7.cend(); it ++) {
        cout << *it << "\t";
    }
    cout << endl;
    
    return 0;
}
