#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// �����ı���ʹ��if elseͳ��Ԫ����ĸ��

int main() {
    char ch = ' ';
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    cout << "�����ı�" << endl;
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
