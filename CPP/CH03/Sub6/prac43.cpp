#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

// ��Χfor��������ָ�������ά���飬�����ͱ�����auto����ѭ�����Ʊ���������
int ia[3][4] = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9, 10, 11
};

int main() {
    // auto
    // ��Χfor
    for (auto &row : ia) {
        for (auto &col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // �±�����
    for (size_t i = 0; i != 3; ++ i) {
        for (size_t j = 0; j != 4; ++ j) {
            cout << ia[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ָ��
    for (auto pr = begin(ia); pr != end(ia); ++ pr) {
        for (auto pc = begin(*pr); pc != end(*pr); ++ pc) {
            cout << *pc << "\t";
        }
        cout << endl;
    }
    cout << endl;
    /*
    using int_array = int[4];   // ���ͱ���
    // ��Χfor
    for (int_array &row : ia) {
        for (int &col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // �±�����
    for (size_t i = 0; i != 3; ++ i) {
        for (size_t j = 0; j != 4; ++ j) {
            cout << ia[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ָ��
    for (int_array *pr = begin(ia); pr != end(ia); ++ pr) {
        for (int *pc = begin(*pr); pc != end(*pr); ++ pc) {
            cout << *pc << "\t";
        }
        cout << endl;
    }
    cout << endl;
    */
    /*
    // ��Χfor
    for (int (&row)[4] : ia) {
        for (int &col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // �±�����
    for (size_t i = 0; i != 3; ++ i) {
        for (size_t j = 0; j != 4; ++ j) {
            cout << ia[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ָ��
    for (int (*pr)[4] = begin(ia); pr != end(ia); ++ pr) {
        for (int *pc = begin(*pr); pc != end(*pr); ++ pc) {
            cout << *pc << "\t";
        }
        cout << endl;
    }
    cout << endl;
    */

    return 0;
}
