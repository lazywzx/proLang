#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;

// �����0�쳣

int main() {
    double a = 0, b = 0;

    while (true) {
        cout << "����������" << endl;
        cin >> a >> b;
        try {
            if (b == 0) {
                throw invalid_argument("����Ϊ0��");
            }
            cout << a / b << endl;
            break;
        } catch (invalid_argument err) {
            cout << err.what() << "\n�������룺yes������������" << endl;
            string rsp = "";
            cin >> rsp;
            if (rsp != "yes") {
                break;
            }
        }
    }

    return 0;
}
