#include <iostream>
#include <gtest/gtest.h>
#include "../lib/lib_a.h"


TEST(TestSample, TestAddition)
{
    ASSERT_EQ(2, add(1,1));
}

int main(int argc, char **argv)
{
    std::cout << "Unit Tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}