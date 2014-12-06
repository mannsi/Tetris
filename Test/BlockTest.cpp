#include "gtest/gtest.h"
#include "../LongBlock.h"

bool VectorContainsPoint(vector<Point>, Point);

TEST(LongBLockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    vector<Point> pointVector = vector<Point>(lb.WorldVector());

    Point expectedPoint1 = {.X=x, .Y=y};
    Point expectedPoint2 = {.X=x, .Y=y - 1};
    Point expectedPoint3 = {.X=x, .Y=y - 2};
    Point expectedPoint4 = {.X=x, .Y=y - 3};

    ASSERT_TRUE(pointVector.size() == 4);
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint1));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint2));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint3));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint4));
}


TEST(LongBLockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    lb.MoveDown();
    vector<Point> pointVector = vector<Point>(lb.WorldVector());

    Point expectedPoint1 = {.X=x, .Y=y - 1};
    Point expectedPoint2 = {.X=x, .Y=y - 2};
    Point expectedPoint3 = {.X=x, .Y=y - 3};
    Point expectedPoint4 = {.X=x, .Y=y - 4};

    ASSERT_TRUE(pointVector.size() == 4);
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint1));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint2));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint3));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint4));
}

TEST(LongBLockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    lb.MoveRight();
    vector<Point> pointVector = vector<Point>(lb.WorldVector());

    Point expectedPoint1 = {.X=x + 1, .Y=y};
    Point expectedPoint2 = {.X=x + 1, .Y=y};
    Point expectedPoint3 = {.X=x + 1, .Y=y};
    Point expectedPoint4 = {.X=x + 1, .Y=y};

    ASSERT_TRUE(pointVector.size() == 4);
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint1));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint2));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint3));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint4));
}

TEST(LongBLockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    lb.MoveLeft();
    vector<Point> pointVector = vector<Point>(lb.WorldVector());

    Point expectedPoint1 = {.X=x - 1, .Y=y};
    Point expectedPoint2 = {.X=x - 1, .Y=y};
    Point expectedPoint3 = {.X=x - 1, .Y=y};
    Point expectedPoint4 = {.X=x - 1, .Y=y};

    ASSERT_TRUE(pointVector.size() == 4);
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint1));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint2));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint3));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint4));
}

TEST(LongBLockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {.X=x, .Y=y};
    LongBlock lb(initialPoint);
    lb.Turn();
    vector<Point> pointVector = vector<Point>(lb.WorldVector());

    Point expectedPoint1 = {.X=x - 1, .Y=y - 1};
    Point expectedPoint2 = {.X=x, .Y=y - 1};
    Point expectedPoint3 = {.X=x + 1, .Y=y - 1};
    Point expectedPoint4 = {.X=x + 2, .Y=y - 1};

    ASSERT_TRUE(pointVector.size() == 4);
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint1));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint2));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint3));
    ASSERT_TRUE(VectorContainsPoint(pointVector, expectedPoint4));
}

bool VectorContainsPoint(vector<Point> pointVector, Point point)
{
    for (int i = 0; i < pointVector.size(); ++i) {
        Point p = pointVector[i];
        if (p == point) return true;
    }
    return false;
}