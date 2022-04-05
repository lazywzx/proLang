#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 求和

int main() {
    vector<int> li{1, 2, 3, 4, 5, 6};
    auto sum = accumulate(li.cbegin(), li.cend(), 0);
    cout << sum << endl;

    return 0;
}
