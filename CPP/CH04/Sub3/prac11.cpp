#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// ��֤�ĸ���ֵ��ϵ

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    cout << "�����ĸ���ֵ��" << endl;
    cin >> a >> b >> c >> d;
    if (a > b && b > c && c > d) {
        cout << "good job" << endl;
    }
    else {
        cout << "bad job" << endl;
    }
    
    return 0;
}
