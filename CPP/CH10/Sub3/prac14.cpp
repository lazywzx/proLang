#include <iostream>

using namespace std;

// 编写lambda，返回两个int的和

auto f = [](const int& a, const int& b) -> int {
    return a + b;
};

int main() {
    cout << f(3, 5) << endl;

    int x = 6;
    auto f2 = [x](const int& a) -> int {
        return a + x;
    };

    cout << f2(8) << endl;

    return 0;
}
