#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 输入一个数，求阶乘

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val --;
    }

    return ret;
}


int main() {
    int num = 0;
    string rsp = "";
    while (true) {
        cout << "输入一个数" << endl;
        cin >> num;
        int res = fact(num);
        cout << num << "的阶乘为" << res << endl;
        cout << "继续输入yes，输入其他结束" << endl;

        cin >> rsp;
        if (rsp != "yes") {
            break;
        }
    }
    
    return 0;
}
