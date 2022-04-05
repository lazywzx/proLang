#include <vector>

using namespace std;

// 六种创建和初始化容器的方法

int main() {
    /* 默认构造函数 */
    vector<int> v1;

    /* 列表初始化 */
    vector<int> v2{1, 2, 3, 4, 5};
    vector<int> v3 = {6, 7, 8, 9, 0};

    /* 拷贝和赋值 */
    vector<int> v4(v2);
    vector<int> v5 = v3;

    /* 迭代器范围 */
    vector<int> v6(v2.begin(), v2.end());

    /* 指定大小 */
    vector<int> v7(5);
    vector<int> v8(5, 1);

    return 0;
}
