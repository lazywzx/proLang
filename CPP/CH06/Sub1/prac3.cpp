#include <iostream>

using std::cout;
using std::endl;

// Çó½×³Ë

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val --;
    }

    return ret;
}


int main() {
    int num = 5;
    int res = fact(num);
    cout << num << "µÄ½×³ËÎª" << res << endl;

    return 0;
}
