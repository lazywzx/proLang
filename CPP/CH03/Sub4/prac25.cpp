#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ʹ�õ�����ͳ�Ʒ����ֲ�
int main() {
    vector<unsigned int> scores(11, 0);
    unsigned int grade;
    auto it = scores.begin();

    cout << "���������˵ķ���" << endl;
    while (cin >> grade) {
        if (grade <= 100) {
            ++ *(it + grade / 10);
        }
    }
    
    cout << "�����ֲ���" << endl;
    for (auto &n : scores) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
