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

// 打印一个istringstream对象

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
    cout << "输入一行" << endl;
    string line("");
    if (getline(cin, line)) {
        istringstream record(line); // 将一行数据存到string流中
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

