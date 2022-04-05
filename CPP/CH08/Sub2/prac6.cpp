#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

// 将文件名作为参数，通过main读取销售记录

int main(int argc, char* argv[]) {
    Sales_data total;
    ifstream infile(argv[1]);   // 打开文件
    if (infile) {   // 判断文件是否正常打开
        if (read(infile, total)) {
            Sales_data trans;
            while (read(infile, trans)) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                }
                else {
                    print(cout, total) << endl;
                    total = trans;
                }
            }
            print(cout, total) << endl;
        }
        else {
            cerr << "No data?!" << endl;
        }
    }
    else {
        cerr << "File open fail!" << endl;
    }

    return 0;
}
