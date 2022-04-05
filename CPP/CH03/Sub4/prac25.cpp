#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 使用迭代器统计分数分布
int main() {
    vector<unsigned int> scores(11, 0);
    unsigned int grade;
    auto it = scores.begin();

    cout << "输入所有人的分数" << endl;
    while (cin >> grade) {
        if (grade <= 100) {
            ++ *(it + grade / 10);
        }
    }
    
    cout << "分数分布：" << endl;
    for (auto &n : scores) {
        cout << n << "\t";
    }
    cout << endl;

    return 0;
}
