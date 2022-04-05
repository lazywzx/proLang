#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

/* Account类 */
class Account {
    /* 私有 */
    private:
        /* 数据成员 */
        std::string owner;
        double amount;
        /* 静态成员 */
        static double interestRate;
        /* 静态成员函数 */
        static double initRate();
    
    /* 公有 */
    public:
        /* 成员函数 */
        void calculate() {
            amount += amount * interestRate;
        }
        /* 静态成员函数 */
        static double rate();
        static void rate(double);

};

/* 在类的外部定义和初始化静态成员函数 */
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