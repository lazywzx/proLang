#include <iostream>
#include <vector>
#include <list>

using namespace std;

// �����ͳ�ʼ������

int main() {
    /* list<int>��ʼ��vector<double> */
    list<int> li{1, 2, 3, 4, 5};
    vector<double> vd(li.begin(), li.end());

    /* vector<int>��ʼ��vector<double> */
    vector<int> vi{1, 2, 3, 4, 5};
    vector<double> vd2(vi.begin(), vi.end());

    for (auto &i : vd) {
        cout << i << "\t";
    }
    cout << endl;

    for (auto &i : vd2) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
