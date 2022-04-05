#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 读入文本，统计元音字母数，考虑大小写字母

int main() {
    char ch = ' ';
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    cout << "输入文本" << endl;
    while (cin >> ch) {
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
            default: {
                ++ otherCnt;
                break;
            }
        }
    }

    cout << aCnt << "\t" << eCnt << "\t" << iCnt << "\t"
         << oCnt << "\t" << uCnt << "\t" << otherCnt << endl;
    
    return 0;
}
