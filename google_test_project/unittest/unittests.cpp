#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
#include "../lib/lib_a.h"


TEST(TestSample, TestAddition)
{
    ASSERT_EQ(2, add(1,1));
}

TEST(AccountTest, TestEmptyAccount)
{
  Account account;

  double balance = account.get_balance();

  ASSERT_EQ(0, balance);
}

class AccountTestFixture: public testing::Test
{
  public:
   AccountTestFixture();
   virtual ~AccountTestFixture();
   void SetUp() override;
   void TearDown() override;
   static void SetUpTestCase();
   static void TearDownTestCase();
  protected:
   Account account;
};

AccountTestFixture::AccountTestFixture()
{
  std::cout << "Constructor called\n";
}

AccountTestFixture::~AccountTestFixture()
{
  std::cout << "Destructor called\n";
}

void AccountTestFixture::SetUpTestCase()
{
  std::cout << "SetUpTestCase called\n";
}

void AccountTestFixture::TearDownTestCase()
{
  std::cout << "TearDownTestCase called\n";
}

void AccountTestFixture::SetUp()
{
    std::cout << "SetUp called\n";
    account.deposit(10.5);
}

void AccountTestFixture::TearDown()
{
    std::cout << "TearDown called\n";
}


TEST_F(AccountTestFixture, TestDeposit)
{ 
  std::cout << "Test body\n";
  ASSERT_EQ(10.5, account.get_balance());
}


TEST_F(AccountTestFixture,  TestWithdrawOK)
{
  account.withdraw(3);

  ASSERT_EQ(7.5, account.get_balance());
}


TEST_F(AccountTestFixture,  TestWithdrawInsufficientFunds)
{
  ASSERT_THROW(account.withdraw(300), std::runtime_error);
}


TEST_F(AccountTestFixture,  TestTransferOK)
{
  Account to;

  account.transfer(to, 2);
  
  ASSERT_EQ(8.5, account.get_balance());
  ASSERT_EQ(2, to.get_balance());
}


TEST_F(AccountTestFixture,  TestTransferInsufficientFunds)
{
  Account to;

  ASSERT_THROW(account.transfer(to, 200), std::runtime_error);
}

// own main shall return RUN_ALL_TESTS()
// https://google.github.io/googletest/primer.html#writing-the-main-function
int main(int argc, char **argv)
{
    std::cout << "Unit Tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
