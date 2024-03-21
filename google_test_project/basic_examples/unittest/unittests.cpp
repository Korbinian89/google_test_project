#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include "../lib/lib_a.h"

//////////////////////////////////////////////////////////////////////////////////
// Lib Simple Test
//////////////////////////////////////////////////////////////////////////////////
TEST(TestSample, TestAddition)
{
    ASSERT_EQ(2, add(1,1));
}




//////////////////////////////////////////////////////////////////////////////////
// Account Class Tests from Lib
// Use Test Fixture
//////////////////////////////////////////////////////////////////////////////////
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


//////////////////////////////////////////////////////////////////////////////////
// Validator Class Test with Parameterized Tests
//////////////////////////////////////////////////////////////////////////////////
class ValidatorFixture : public testing::TestWithParam<std::tuple<int, bool>>
{
public:
protected:
 Validator mValidator{5, 10};
};

TEST_P(ValidatorFixture, TestInRange)
{
  std::tuple<int, bool> tuple = GetParam();

  int param = std::get<0>(tuple);
  bool expectedValue = std::get<1>(tuple);

  std::cout << "param = " << param << " expected value = " << expectedValue << '\n';

  bool isInside = mValidator.in_range(param);

  ASSERT_EQ(expectedValue, isInside);
}

// with value generator testing::Values
INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, testing::Values(
                                                          std::make_tuple(-50, false),
                                                          std::make_tuple(4, false),
                                                          std::make_tuple(5, true),
                                                          std::make_tuple(6, true),
                                                          std::make_tuple(7, true),
                                                          std::make_tuple(9, true),
                                                          std::make_tuple(10, true),
                                                          std::make_tuple(11, false),
                                                          std::make_tuple(100, false)
));


//////////////////////////////////////////////////////////////////////////////////
// Mocking
//////////////////////////////////////////////////////////////////////////////////
class MyMockedClass : public MyClass
{
public:
    MyMockedClass() = default;
    MOCK_METHOD0(my_method, void());
};


TEST(TestMyClass, TestMock)
{
    MyMockedClass mc;
    mc.my_method();
}

//////////////////////////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
