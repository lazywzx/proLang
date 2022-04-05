#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

/* Account�� */
class Account {
    /* ˽�� */
    private:
        /* ���ݳ�Ա */
        std::string owner;
        double amount;
        /* ��̬��Ա */
        static double interestRate;
        /* ��̬��Ա���� */
        static double initRate();
    
    /* ���� */
    public:
        /* ��Ա���� */
        void calculate() {
            amount += amount * interestRate;
        }
        /* ��̬��Ա���� */
        static double rate();
        static void rate(double);

};

/* ������ⲿ����ͳ�ʼ����̬��Ա���� */
double Account::initRate() {
    return 0.0;
}
double Account::interestRate = initRate();

double Account::rate() {
    return interestRate;
}
void Account::rate(double r) {
    interestRate = r;
}

#endif