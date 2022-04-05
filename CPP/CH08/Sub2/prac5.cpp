#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

// ��ģʽ���ļ�����ÿ�����ʴ浽������

vector<string> read_file(const string& path) {
    ifstream infile(path);
    if(infile) {    // �ж��ļ��Ƿ�ɹ���
        string word("");
        vector<string> vs{};
        while (infile >> word) {
            vs.push_back(word); // ��ӵ�������
        }
        return vs;
    }
    else {
        cerr << "�ļ���ʧ��!" << endl;
    }
}

int main() {
    string path(".\\data.txt");

    vector<string> vs = read_file(path);
    for (auto& s : vs) {
        cout << s << endl;
    }

    return 0;
}

