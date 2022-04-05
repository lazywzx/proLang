#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 读入一组数，输出相邻的和
int main() {
    int num;
    vector<int> numbers;
    cout << "输入一组数" << endl;
    while (cin >> num) {
        numbers.push_back(num);
    }

    for (decltype(numbers.size()) n = 0; n <= numbers.size() - 1 - n; n ++) {
        cout << numbers[n] + numbers[numbers.size() - 1 - n] << "\t";
    }
    cout << endl;
    
    /*
    for (decltype(numbers.size()) n = 0; n < numbers.size() - 1; n ++) {
        cout << numbers[n] + numbers[n + 1] << "\t";
    }
    cout << endl;
    */

    return 0;
}
