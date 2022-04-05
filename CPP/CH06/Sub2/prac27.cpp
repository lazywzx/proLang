#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

// �ɱ������β�

void sum(initializer_list<int> lst) {
    int s = 0;
    for (const auto &n : lst) {
        s += n;
    }
    cout << "�����б�ĺ�Ϊ��" << s << endl;
}

int main() {
    sum({1, 2, 3, 4, 5});

    return 0;
}
