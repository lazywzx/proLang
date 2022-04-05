#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

// 将文件中的行保存在容器中，然后从容器中每次读取一个单词
// 将istringstream类对象的定义移到循环外

int main(int argc, char* argv[]) {
    string path = argv[1];
    vector<string> vs{};

    /* 文件行存到容器 */
    ifstream infile(path);  // 读入文件
    if (infile) {// 文件被正确打开
        string line("");
        while (getline(infile, line)) {
            vs.push_back(line); // 存下一行数据
        }
    }
    else {
        cerr << "File open fail!" << endl;
    }

    /* 输出单词 */
    string word("");
    istringstream line;
    for (auto& l : vs) {
        line.str(l);
        while (line >> word) {
            cout << word << " ";
        }
        cout << endl;
        line.clear();
    }

    return 0;
}
