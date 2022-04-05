#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// �����ı���ͳ��Ԫ����ĸ�������Ǵ�Сд��ĸ��ͳ�ƿո��Ʊ����У�ͳ���ַ����У�ff��fl��fi

int main() {
    char ch = 0;
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int otherCnt = 0, spaceCnt = 0, tabCnt = 0, enterCnt = 0;
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    bool ffFlag = false;

    cout << "�����ı�" << endl;
    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case 'a':
            case 'A': {
                ++ aCnt;
                ffFlag = false;
                break;
            }
            case 'e':
            case 'E': {
                ++ eCnt;
                ffFlag = false;
                break;
            }
            case 'i': {
                if (ffFlag) {
                    ++ fiCnt;
                }
            }
            case 'I': {
                ++ iCnt;
                ffFlag = false;
                break;
            }
            case 'o':
            case 'O': {
                ++ oCnt;
                ffFlag = false;
                break;
            }
            case 'u':
            case 'U': {
                ++ uCnt;
                ffFlag = false;
                break;
            }
            case ' ': {
                ++ spaceCnt;
                ffFlag = false;
                break;
            }
            case '\t': {
                ++ tabCnt;
                ffFlag = false;
                break;
            }
            case '\n': {
                ++ enterCnt;
                ffFlag = false;
                break;
            }
            case 'f': {
                if (ffFlag) {
                    ++ ffCnt;
                }
                ffFlag = true;
                break;
            }
            case 'l': {
                if (ffFlag) {
                    ++ flCnt;
                }
                ffFlag = false;
                break;
            }
            default: {
                ++ otherCnt;
                ffFlag = false;
                break;
            }
        }
    }

    cout << aCnt << "\t" << eCnt << "\t" << iCnt << "\t"
         << oCnt << "\t" << uCnt << "\t" << otherCnt << "\t" 
         << spaceCnt << "\t" << tabCnt << "\t" << enterCnt << "\t"
         << ffCnt << "\t" << flCnt << "\t" << fiCnt << endl;
    
    return 0;
}
