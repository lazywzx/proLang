#include <iostream>

using std::cout;
using std::endl;

// 返回引用类型的函数

int &get(int *arr, int index) {
    return arr[index];
}

int main() {
    int ia[10];
    for (int i = 0; i != 10; ++ i) {
        get(ia, i) = i;
    }

    for (auto &n : ia) {
        cout << n << "\t";
    }
    cout << endl;
    
    return 0;
}
