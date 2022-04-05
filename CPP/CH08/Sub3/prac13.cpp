#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// �绰���봦�����

/* ���˵绰������ */
class Phone {
    public:
        string name;    // ����
        vector<string> phone_num;   // �绰����
};

/* ��ȡ�ļ� */
void read_data(const string& path, vector<Phone>& peo) {
    ifstream infile(path);
    if (infile) {
        string line, word;
        Phone tmp;
        istringstream l;
        // ��ȡÿһ��
        while (getline(infile, line)) {
            l.str(line);
            l >> word;  // ��ȡ����
            tmp.name = word;
            tmp.phone_num = {}; // �����һ���˵�����
            while (l >> word) {
                tmp.phone_num.push_back(word);  // ��ȡ���е绰����
            }
            peo.push_back(tmp);  // �洢ÿ���˵�����
            l.clear();
        }
    }
    else {
        cerr << "File open fail!" << endl;
    }
}

/* �Ϸ�����֤ */
inline bool vaild(const string& num) {
    return (num.size() == 11) ? true : false;
}

/* ��ʽת�� */
inline string formate(const string& num) {
    return "+86" + num;
}

/* �Ϸ�����������ļ� */
inline void write_data(const string& path, const string& info) {
    ofstream outfile(path, ofstream::app);
    outfile << info << endl;
}

/* �Ƿ����ݴ�ӡ���ն� */
inline void print_data(const string& info) {
    cout << "BAD DATA: " << info << endl;
}

/* ��Ҫ������ */
void process(const vector<Phone>& people, const string& outpath) {
    cout << "��ʼ����..." << endl;
    // ����ÿ����
    for (const auto& p : people) {
        ostringstream good, bad;
        for (const auto& n : p.phone_num) {
            // ��֤��������е绰����
            if (vaild(n)) {
                // ��ʽ��ȷ��ת����ʽ
                good << " " << formate(n);
            }
            else {
                bad << " " << n;
            }
        }
        // �Ϸ�����д���ļ����Ƿ����ݴ�ӡ���ն�
        write_data(outpath, p.name + " " + good.str());
        if (!bad.str().empty())
            print_data(p.name + " " + bad.str());
    }
    cout << "������ɣ�" << endl;
}

/* ������ */
int main(int argc, char* argv[]) {
    // ���������˵���Ϣ��ԭʼ����
    vector<Phone> people{};
    read_data(argv[2], people);
    process(people, argv[4]);

    return 0;
}
