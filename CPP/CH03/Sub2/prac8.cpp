#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// ʹ��while��ͳfor���ַ��������ַ��޸�ΪX
int main()
{
    string line;
    cout << "����һ���ַ���" << endl;
    while (getline(cin, line)) {
        if (!line.empty()) {
            for (decltype(line.size()) ls = 0; ls < line.size(); ls ++) {
                line[ls] = 'X';
            }
            /*
            decltype(line.size()) ls = 0;
            while (ls < line.size()) {
                line[ls] = 'X';
                ++ ls;
            }
            */
            cout << "�޸������ַ�ΪX" << endl;
            cout << line << endl;
        }
        else {
            cout << "empty string!" << endl;
        }
    }

    return 0;    
}
