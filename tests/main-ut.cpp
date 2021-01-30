#include <gtest/gtest.h>

class MainTest : public ::testing::Test {
public:
};

TEST_F(MainTest, ShouldDoNothing)
{
    EXPECT_EQ(1,1);
}

TEST_F(MainTest, ShouldDoNothingSecondTime)
{
    EXPECT_EQ(1,1);
}