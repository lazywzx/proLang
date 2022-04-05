#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

// ���ļ�����Ϊ������ͨ��main��ȡ���ۼ�¼�������������ļ�
// ��׷�ӷ�ʽ������ļ�

int main(int argc, char* argv[]) {
    Sales_data total;
    ifstream infile(argv[1]);   // ���ļ�
    ofstream outfile(argv[2], ofstream::app);  // ����ļ���׷��ģʽ

    if (infile && outfile) {   // �ж��ļ��Ƿ�������
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
