#include <iostream>
#include <fstream>
#include "TextQuery.h"

using namespace std;

// 测试文本查询程序

void runQueries(ifstream& infile) {
    TextQuery tq(infile);
    cout << "输入要查询的单词，输入!q结束程序。" << endl;
    string s;
    while (true) {
        if (cin >> s) {
            if (s == "!q") {
                cout << "bye!" << endl;
                break;
            }
            auto qr = tq.query(s);
            print(cout, qr);
            cout << "\n查询成功，您可继续查询或输入!q退出" << endl;
        }
        else {
            cerr << "输入数据错误，请重新输入。" << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream data(argv[1]);
    runQueries(data);

    return 0;
}
