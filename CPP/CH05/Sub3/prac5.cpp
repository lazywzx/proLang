#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// 使用if else将数字成绩转换为字母成绩

int main() {
    int grade = 86;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade = "";
    
    if (grade < 60) {
        lettergrade = scores[0];
    }
    else {
        lettergrade = scores[(grade - 50) / 10];
        if (grade != 100) {
            if (grade % 10 > 7) {
                lettergrade += "+";
            }
            else if (grade % 10 < 3) {
                lettergrade += "-";
            }
        }
    }

    cout << lettergrade << endl;

    return 0;
}
