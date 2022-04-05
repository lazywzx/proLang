#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

// 使用流迭代器读取文件，存入vector<string>

int main() {
    ifstream infile(".\\text.txt");
    istream_iterator<string> iis(infile), eof;
    vector<string> vs;

    while (iis != eof) {
        vs.push_back(*iis++);
    }

    for (auto& s : vs) {
        cout << s << "\t";
    }
    cout << endl;

    return 0;
}
