#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// �޳��ַ����еı�����
int main()
{
    string line;
    string result;
    cout << "����һ�δ������ŵ��ַ���" << endl;
    while (getline(cin, line)) {
        if (!line.empty()) {
            for (auto &c : line) {
                if (!ispunct(c)) {
                    result += c;
                }
            }
            cout << "�޳�������" << endl;
            cout << result << endl;
        }
        else {
            cout << "empty string!" << endl;
        }
    }

    return 0;    
}
