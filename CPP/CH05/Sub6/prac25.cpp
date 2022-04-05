#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;

// 处理除0异常

int main() {
    double a = 0, b = 0;

    while (true) {
        cout << "输入两个数" << endl;
        cin >> a >> b;
        try {
            if (b == 0) {
                throw invalid_argument("除数为0！");
            }
            cout << a / b << endl;
            break;
        } catch (invalid_argument err) {
            cout << err.what() << "\n重新输入：yes，结束：其他" << endl;
            string rsp = "";
            cin >> rsp;
            if (rsp != "yes") {
                break;
            }
        }
    }

    return 0;
}
