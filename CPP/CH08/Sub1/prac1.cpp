#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

// ��ȡ�������״̬

istream& func_stream(istream& i) {
    while (!i.eof()) {
        string tmp("");
        i >> tmp;
        cout << tmp;
    }
    i.clear();
    return i;
}

int main() {
    cout << "�������ݣ�" << endl;
    func_stream(cin);

    return 0;
}
