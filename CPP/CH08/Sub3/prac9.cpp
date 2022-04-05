#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::istringstream;

// ��ӡһ��istringstream����

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
    cout << "����һ��" << endl;
    string line("");
    if (getline(cin, line)) {
        istringstream record(line); // ��һ�����ݴ浽string����
        string word;
        while (record >> word) {
            cout << word << "\t";
        }
        cout << endl;
    }
    else {
        cerr << "Input error!" << endl;
    }

    return 0;
}

