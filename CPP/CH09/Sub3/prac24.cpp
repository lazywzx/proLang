#include <vector>
#include <iostream>

using namespace std;

// ��������Ԫ�أ����Կ�����

int main() {
    // vector<int> vi{1, 2, 3, 4};
    vector<int> vi{};

    /* at[n] */
    cout << vi.at(0) << endl;

    /* �±� */
    cout << vi[0] << endl;

    /* front */
    cout << vi.front() << endl;

    /* begin() */
    cout << *(vi.cbegin()) << endl;

    return 0;
}
