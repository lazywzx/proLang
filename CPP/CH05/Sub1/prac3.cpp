#include <iostream>

using std::cout;
using std::endl;

// 使用逗号运算符省略语句块

int main() {
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++ val;
    
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;

    return 0;
}
