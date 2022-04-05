#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

// �����������ִ������ĵ��ʣ�û���Ƕ�����������

int main() {
    int maxCnt = 1, currentCnt = 1;
    string maxWord = "", currentWord = "";
    vector<string> svec = {};

    cout << "����һ�鵥��" << endl;
    while (cin >> currentWord) {
        svec.push_back(currentWord);
    }

    if (svec.size() < 2) {
        cerr << "���뵥������С��2��" << endl;
        return -1;
    }

    auto it = svec.cbegin() + 1;
    for (; it != svec.cend(); ++ it) {
        if (*it == *(it - 1)) {
            ++ currentCnt;
            currentWord = *it;
        }
        else {
            if (currentCnt > maxCnt) {
                maxCnt = currentCnt;
                maxWord = currentWord;
            }
            currentCnt = 1;
        }
    }

    if (maxCnt == 1) {
        cout << "û�е����������ֹ�" << endl;
    }
    else {
        cout << "�������ִ������ĵ����ǣ�" << maxWord << ", ����������" << maxCnt << "�Ρ�" << endl;
    }

    return 0;
}
