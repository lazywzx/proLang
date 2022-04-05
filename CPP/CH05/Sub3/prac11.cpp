#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// �����ı���ͳ��Ԫ����ĸ�������Ǵ�Сд��ĸ��ͳ�ƿո��Ʊ�����

int main() {
    char ch = 0;
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int otherCnt = 0, spaceCnt = 0, tabCnt = 0, enterCnt = 0;
    cout << "�����ı�" << endl;
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
