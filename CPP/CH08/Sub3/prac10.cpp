#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

// ���ļ��е��б����������У�Ȼ���������ÿ�ζ�ȡһ������
// ��istringstream�����Ķ����Ƶ�ѭ����

int main(int argc, char* argv[]) {
    string path = argv[1];
    vector<string> vs{};

    /* �ļ��д浽���� */
    ifstream infile(path);  // �����ļ�
    if (infile) {// �ļ�����ȷ��
        string line("");
        while (getline(infile, line)) {
            vs.push_back(line); // ����һ������
        }
    }
    else {
        cerr << "File open fail!" << endl;
    }

    /* ������� */
    string word("");
    istringstream line;
    for (auto& l : vs) {
        line.str(l);
        while (line >> word) {
            cout << word << " ";
        }
        cout << endl;
        line.clear();
    }

    return 0;
}
