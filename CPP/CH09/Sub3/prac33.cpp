#include <iostream>
#include <vector>

using namespace std;

// ��֤����Ԫ�غ������ָ���������Ԫ��

int main() {
    vector<int> li{0, 1, 2, 3, 4, 5};
    auto iter = li.begin();
    while (iter != li.end()) {
        ++ iter;
        li.insert(iter, 42);    // ������ʧЧ��
        ++ iter;    // �����������ʧЧ
    }

    for (auto& i : li) {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}
