#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// �����ݸ�main��ʵ�����

int main(int argc, char* argv[]) {
    string s = "";
    for (int i = 1; i != argc; ++ i) {
        cout << s + argv[i] << "\t";
    }
    cout << endl;

    return 0;
}
