#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// ʹ����������������ֳɼ�ת��Ϊ��ĸ�ɼ�

int main() {
    int grade = 86;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade = "";

    (grade < 60) ? (lettergrade = scores[0]) : ((lettergrade = scores[(grade - 50) / 10]), (grade != 100) ? ((grade % 10 > 7) ? (lettergrade += "+") : ((grade % 10 < 3) ? (lettergrade += "-") : lettergrade)) : lettergrade);

    cout << lettergrade << endl;

    return 0;
}
