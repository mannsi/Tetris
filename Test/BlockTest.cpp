#include "gtest/gtest.h"
#include "../LongBlock.h"

TEST(BlockTests, LongBlock)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    lb.WorldVector();
    ASSERT_TRUE(false);
}