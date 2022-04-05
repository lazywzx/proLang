#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

// 读模式打开文件，将每个单词存到容器中

vector<string> read_file(const string& path) {
    ifstream infile(path);
    if(infile) {    // 判断文件是否成功打开
        string word("");
        vector<string> vs{};
        while (infile >> word) {
            vs.push_back(word); // 添加到容器中
        }
        return vs;
    }
    else {
        cerr << "文件打开失败!" << endl;
    }
}

int main() {
    string path(".\\data.txt");

    vector<string> vs = read_file(path);
    for (auto& s : vs) {
        cout << s << endl;
    }

    return 0;
}

