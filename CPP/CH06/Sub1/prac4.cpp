#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ����һ��������׳�

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
        cout << "����һ����" << endl;
        cin >> num;
        int res = fact(num);
        cout << num << "�Ľ׳�Ϊ" << res << endl;
        cout << "��������yes��������������" << endl;

        cin >> rsp;
        if (rsp != "yes") {
            break;
        }
    }
    
    return 0;
}
