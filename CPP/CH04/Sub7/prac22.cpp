#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

// 使用条件运算符和条件判断语句

int main() {
    int grade = 80;
    string final_grade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";
    cout << final_grade << endl;

    if (grade > 90) {
        final_grade = "high pass";
    }
    else if (grade > 75) {
        final_grade = "pass";
    }
    else if (grade > 60) {
        final_grade = "low pass";
    }
    else {
        final_grade = "fail";
    }
    cout << final_grade << endl;

    return 0;
}
