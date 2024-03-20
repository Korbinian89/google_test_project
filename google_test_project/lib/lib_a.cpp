#include "lib_a.h"
#include <stdexcept>

int add(int a, int b)
{
    return a + b;
}

void Account::deposit(double iSum)
{
    mBalance += iSum;
}

void Account::withdraw(double iSum)
{
    if (mBalance < iSum)
    {
        throw std::runtime_error("Insufficient funds");
    }
    mBalance -= iSum;
}

double Account::get_balance() const
{
    return mBalance;
}

void Account::transfer(Account& iTo, double iSum)
{
    withdraw(iSum);
    iTo.deposit(iSum);
}