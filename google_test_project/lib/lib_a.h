// lib definitions
#pragma once

int add(int a, int b);


class Account
{
public:
    Account() = default;
    void deposit(double iSum);
    void withdraw(double iSum);
    double get_balance() const;
    void transfer(Account& iTo, double iSum);
private:
    double mBalance = 0.0;
};