#include <iostream>
#include <vector>
#include <list>

using namespace std;

// �Ƚ�vector<int>��list<int>

int main() {
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2{1, 2, 3, 4};
    list<int> v3{1, 2, 3, 4};

    if (v1.size() != v3.size()) {
        cout << "��ͬ" << endl;
        return 0;
    }

    auto v1b = v1.cbegin();
    auto v3b = v3.cbegin();
    for (; v1b != v1.cend() && v3b != v3.cend(); ++ v1b, ++ v3b) {
        if (*v1b != *v3b) {
            cout << "��ͬ" << endl;
            return 0;
        }
    }


    cout << "��ͬ" << endl;
    return 0;
}