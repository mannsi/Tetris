#include "gtest/gtest.h"
#include "../LongBlock.h"
#include "../BoxBlock.h"

bool VectorContainsPoint(vector<Point>, Point);
void Assert_VectorsContainSamePoints(vector<Point>, vector<Point>);

TEST(LongBLockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x, y},
        {x, y - 1},
        {x, y - 2},
        {x, y - 3}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBLockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveDown();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x, y - 1},
        {x, y - 2},
        {x, y - 3},
        {x, y - 4}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBLockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveRight();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x + 1, y},
        {x + 1, y},
        {x + 1, y},
        {x + 1, y}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBLockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveLeft();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x - 1, y},
        {x - 1, y},
        {x - 1, y},
        {x - 1, y}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBLockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.Turn();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x - 1, y - 1},
        {x, y - 1},
        {x + 1, y - 1},
        {x + 2, y - 1}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}


TEST(BoxBLockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x, y},
        {x + 1, y},
        {x, y - 1},
        {x + 1, y - 1}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBLockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveDown();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x, y - 1},
        {x + 1, y - 1},
        {x, y - 2},
        {x + 1, y - 2}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBLockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveRight();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x + 1, y},
        {x + 2, y},
        {x + 1, y - 1},
        {x + 2, y - 1}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBLockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveLeft();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x - 1, y},
        {x, y},
        {x - 1, y - 1},
        {x, y - 1}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBLockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.Turn();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x, y},
        {x + 1, y},
        {x, y - 1},
        {x + 1, y - 1}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

void Assert_VectorsContainSamePoints(vector<Point> v1, vector<Point> v2)
{
    ASSERT_TRUE(v1.size() == v2.size());
    for (int i = 0; i < v2.size(); ++i) {
        ASSERT_TRUE(VectorContainsPoint(v1, v2[i]));
    }
}

bool VectorContainsPoint(vector<Point> blockVector, Point point)
{
    for (int i = 0; i < blockVector.size(); ++i) {
        Point p = blockVector[i];
        if (p == point) return true;
    }
    return false;
}