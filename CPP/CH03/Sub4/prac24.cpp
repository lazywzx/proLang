#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ����һ������������ڵĺ�
int main() {
    int num;
    vector<int> numbers;
    cout << "����һ����" << endl;
    while (cin >> num) {
        numbers.push_back(num);
    }

    for (auto itb = numbers.cbegin(), ite = numbers.cend() - 1; itb <= ite; ++ itb, -- ite) {
        cout << *ite + *itb << "\t";
    }

   /*
    for (auto it = numbers.cbegin(); it != numbers.cend() - 1; ++ it) {
        cout << *it + *(it + 1) << "\t";
    }
    */
    cout << endl;

    return 0;
}
