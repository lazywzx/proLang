#include <iostream>
#include <list>
#include <deque>

using namespace std;

// ��list<int>�н�ż��������deque�У�������������һ��deque

int main() {
    list<int> li{1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> di1{}, di2{};

    for (auto& i : li) {
        if (i % 2) {
            di1.push_back(i);
        }
        else {
            di2.push_back(i);
        }
    }

    cout << "������" << endl;
    for (auto& i : di1) {
        cout << i << "\t";
    }

    cout << endl << "ż����" << endl;
    for (auto& i : di2) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}