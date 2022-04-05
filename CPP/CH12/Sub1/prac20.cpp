#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StrBlob.h"

using namespace std;

// 逐行读入输入文件内容，存入到StrBlob中，用StrBlobPtr打印内容

int main(int argc, char* argv[]) {
    fstream datafile(argv[1]);
    if (datafile) {
        StrBlob blob;
        string line;
        while (getline(datafile, line)) {
            blob.push_back(line);
        }

        /* 使用指针打印元素 */
        auto pb = blob.begin();
        for (vector<string>::size_type i = 0; i != blob.size(); ++ i) {
            cout << pb.deref() << endl;
            pb.incr();
        }
    }
    else {
        cerr << "文件读取失败" << endl;
    }

    return 0;
}
