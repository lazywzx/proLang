#include <iostream>
#include <list>
#include <string>

using namespace std;

// �ӱ�׼�����ȡstring���д���list�У��õ�������ӡ

int main() {
    list<string> ls{};
    cout << "����string����" << endl;

    string word("");
    while (cin >> word) {
        ls.push_back(word);
    }

    for (auto lsb = ls.cbegin(), lse = ls.cend(); lsb != lse; ++ lsb) {
        cout << *lsb << " ";
    }
    cout << endl;

    return 0;
}
