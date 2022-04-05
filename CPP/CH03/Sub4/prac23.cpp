#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 将容器中所有元素乘2
int main() {
    vector<int> num{1, 2, 3, 4, 5, 6, 7, 23, 44, 55};
    for (auto it = num.begin(); it != num.end(); ++ it) {
        (*it) *= 2;
    }
    for (auto &n : num) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
