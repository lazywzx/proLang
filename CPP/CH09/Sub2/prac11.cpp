#include <vector>

using namespace std;

// ���ִ����ͳ�ʼ�������ķ���

int main() {
    /* Ĭ�Ϲ��캯�� */
    vector<int> v1;

    /* �б��ʼ�� */
    vector<int> v2{1, 2, 3, 4, 5};
    vector<int> v3 = {6, 7, 8, 9, 0};

    /* �����͸�ֵ */
    vector<int> v4(v2);
    vector<int> v5 = v3;

    /* ��������Χ */
    vector<int> v6(v2.begin(), v2.end());

    /* ָ����С */
    vector<int> v7(5);
    vector<int> v8(5, 1);

    return 0;
}
