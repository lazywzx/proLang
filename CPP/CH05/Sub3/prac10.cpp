#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// �����ı���ͳ��Ԫ����ĸ�������Ǵ�Сд��ĸ

int main() {
    char ch = ' ';
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    cout << "�����ı�" << endl;
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
