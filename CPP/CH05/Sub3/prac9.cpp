#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 读入文本，使用if else统计元音字母数

int main() {
    char ch = ' ';
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    cout << "输入文本" << endl;
    while (cin >> ch) {
        if (ch == 'a') {
            ++ aCnt;
        }
        else if (ch == 'e') {
            ++ eCnt;
        }
        else if (ch == 'i') {
            ++ iCnt;
        }
        else if (ch == 'o') {
            ++ oCnt;
        }
        else if (ch == 'u') {
            ++ uCnt;
        }
    }

    cout << aCnt << "\t" << eCnt << "\t" << iCnt << "\t" << oCnt << "\t" << uCnt << endl;
    
    return 0;
}
