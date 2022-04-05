#include <vector>
#include <iostream>

using namespace std;

// 探究vector是如何增长的

int main() {
    cout << "大小: " << "\t容量：" << endl;

    /* 刚创建 */
    vector<int> li;
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 添加十个元素 */
    for (int i = 0; i != 10; ++ i) {
        li.push_back(i);
    }
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 指定分配50个元素空间 */
    li.reserve(50);
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 继续添加元素 */
    for (int i = 0; i != 10; ++ i) {
        li.push_back(i);
    }
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 继续添加元素，将内存占满 */
    for (int i = 0; i != 30; ++ i) {
        li.push_back(i);
    }
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 再添加一个元素，使内存重新分配 */
    li.push_back(0);
    cout << li.size() << "\t" << li.capacity() << endl;

    /* 回收内存 */
    li.shrink_to_fit();
    cout << li.size() << "\t" << li.capacity() << endl;

    return 0;
}
