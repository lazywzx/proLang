#include <iostream>
#include <deque>
#include <string>

using namespace std;

// �ӱ�׼�����ȡstring���д���deque�У��õ�������ӡ

int main() {
    deque<string> ds{};
    cout << "����string����" << endl;

    string word("");
    while (cin >> word) {
        ds.push_back(word);
    }

    for (auto dsb = ds.cbegin(), dse = ds.cend(); dsb != dse; ++ dsb) {
        cout << *dsb << " ";
    }
    cout << endl;

    return 0;
}
