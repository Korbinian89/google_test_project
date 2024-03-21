// Library definition
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


class Validator
{
public:
    Validator(int low, int high);
    bool in_range(int iValueToTest);
private:
    int mLow = 0, mHigh = 0;
};



class MyClass
{
public:
    MyClass() = default;
    virtual void my_method();
};

