#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ����һ��ʣ�����vector�����дʸ�Ϊ��д
int main() {
    string word;
    vector<string> words;

    while (cin >> word) {
        words.push_back(word);
    }
    
    for (auto &w : words) {
        for (auto &c : w) {
            c = toupper(c);
        }
    }
    cout << "������" << words.size() << endl;
    cout << "���ݣ�" << endl;
    for (auto &w : words) {
        cout << w << endl;
    }

    return 0;
}
