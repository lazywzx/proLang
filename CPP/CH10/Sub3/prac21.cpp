#include <iostream>

using namespace std;

// 使用lambda监测变量

int main() {
    int val = 8;
    auto zero = [&val]() -> bool {
        if (val) {
            -- val;
            return false;
        }
        else {
            return true;
        }
    };

    for (int i = 0; i != 10; ++ i) {
        cout << zero() << "\t";
    }
    cout << endl;

    return 0;
}
