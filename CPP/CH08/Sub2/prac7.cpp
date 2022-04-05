#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

// 将文件名作为参数，通过main读取销售记录，将结果输出到文件
// 以追加方式输出到文件

int main(int argc, char* argv[]) {
    Sales_data total;
    ifstream infile(argv[1]);   // 打开文件
    ofstream outfile(argv[2], ofstream::app);  // 输出文件，追加模式

    if (infile && outfile) {   // 判断文件是否正常打开
        if (read(infile, total)) {
            Sales_data trans;
            while (read(infile, trans)) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                }
                else {
                    if (print(outfile, total) << endl) {
                        total = trans;
                    }
                    else {
                        cerr << "Write fail!" << endl;
                    }
                }
            }
            if (!(print(outfile, total) << endl)) {
                cerr << "Write fail!" << endl;
            }
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
