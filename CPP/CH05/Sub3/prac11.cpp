#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 读入文本，统计元音字母数，考虑大小写字母，统计空格、制表、换行

int main() {
    char ch = 0;
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int otherCnt = 0, spaceCnt = 0, tabCnt = 0, enterCnt = 0;
    cout << "输入文本" << endl;
    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case 'a':
            case 'A': {
                ++ aCnt;
                break;
            }
            case 'e':
            case 'E': {
                ++ eCnt;
                break;
            }
            case 'i':
            case 'I': {
                ++ iCnt;
                break;
            }
            case 'o':
            case 'O': {
                ++ oCnt;
                break;
            }
            case 'u':
            case 'U': {
                ++ uCnt;
                break;
            }
            case ' ': {
                ++ spaceCnt;
                break;
            }
            case '\t': {
                ++ tabCnt;
                break;
            }
            case '\n': {
                ++ enterCnt;
                break;
            }
            default: {
                ++ otherCnt;
                break;
            }
        }
    }

    cout << aCnt << "\t" << eCnt << "\t" << iCnt << "\t"
         << oCnt << "\t" << uCnt << "\t" << otherCnt << "\t" 
         << spaceCnt << "\t" << tabCnt << "\t" << enterCnt << endl;
    
    return 0;
}
