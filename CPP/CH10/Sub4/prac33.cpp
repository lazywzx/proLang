#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

// 将输入文件的奇数和偶数分别输出到两个文件，奇数空格分隔，偶数独占一行
// 使用输入输出流迭代器

int main(int argc, char* argv[]) {
    /* 输入文件 */
    ifstream infile(argv[2]);
    /* 输出文件 */
    ofstream even(argv[4]);
    ofstream odd(argv[6]);
    /* 是否正常打开 */
    if (infile) {
        /* 输入输出流 */
        istream_iterator<int> read(infile), eof;
        ostream_iterator<int> e_out(even, "\n");
        ostream_iterator<int> o_out(odd, " ");
        /* 判断奇偶 */
        while (read != eof) {
            if (*read % 2) {
                /* 奇数 */
                *o_out = *read;
                ++ read;
                ++ o_out;
            }
            else {
                /* 偶数 */
                *e_out = *read;
                ++ read;
                ++ e_out;
            }
        }
    }
    else {
        /* 文件打开失败 */
        cerr << "Faile to open the file!" << endl;
    }

    return 0;
}
