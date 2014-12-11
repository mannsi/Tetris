#include "gtest/gtest.h"
#include "../LongBlock.h"
#include "../BoxBlock.h"
#include "TBlock.h"

bool VectorContainsPoint(vector<Point>, Point);
void Assert_VectorsContainSamePoints(vector<Point>, vector<Point>);

TEST(LongBlockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x + 2, y},
        {x + 2, y - 1},
        {x + 2, y - 2},
        {x + 2, y - 3}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBlockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveDown();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 2, y - 1},
                    {x + 2, y - 2},
                    {x + 2, y - 3},
                    {x + 2, y - 4}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBlockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveRight();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 3, y},
                    {x + 3, y - 1},
                    {x + 3, y - 2},
                    {x + 3, y - 3}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBlockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.MoveLeft();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y},
                    {x + 1, y - 1},
                    {x + 1, y - 2},
                    {x + 1, y - 3}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(LongBlockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    LongBlock lb(initialPoint);
    lb.Turn();
    vector<Point> blockVector = vector<Point>(lb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x, y - 1},
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 3, y - 1}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}


TEST(BoxBlockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
    {
        {x + 1, y - 1},
        {x + 2, y - 1},
        {x + 1, y - 2},
        {x + 2, y - 2}
    };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBlockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveDown();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 2},
                    {x + 2, y - 2},
                    {x + 1, y - 3},
                    {x + 2, y - 3}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBlockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveRight();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 2, y - 1},
                    {x + 3, y - 1},
                    {x + 2, y - 2},
                    {x + 3, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(BoxBlockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.MoveLeft();
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

TEST(BoxBlockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    BoxBlock bb(initialPoint);
    bb.Turn();
    vector<Point> blockVector = vector<Point>(bb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 1, y - 2},
                    {x + 2, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}


TEST(TeeBlockTest, New)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 3, y - 1},
                    {x + 2, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, MoveDown)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.MoveDown();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 2},
                    {x + 2, y - 2},
                    {x + 3, y - 2},
                    {x + 2, y - 3}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, MoveRight)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.MoveRight();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 2, y - 1},
                    {x + 3, y - 1},
                    {x + 4, y - 1},
                    {x + 3, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, MoveLeft)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.MoveLeft();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x, y - 1},
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 1, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, Turn)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.Turn();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 2, y},
                    {x + 2, y - 1},
                    {x + 2, y - 2},
                    {x + 3, y - 1}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}


TEST(TeeBlockTest, TurnTwice)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.Turn();
    tb.Turn();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 2, y},
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 3, y - 1}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, TurnThrice)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.Turn();
    tb.Turn();
    tb.Turn();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 1},
                    {x + 2, y},
                    {x + 2, y - 1},
                    {x + 2, y - 2}
            };

    Assert_VectorsContainSamePoints(blockVector, expectedBlockVector);
}

TEST(TeeBlockTest, TurnFour)
{
    int x = 5;
    int y = 5;
    Point initialPoint = {x, y};
    TeeBlock tb(initialPoint);
    tb.Turn();
    tb.Turn();
    tb.Turn();
    tb.Turn();
    vector<Point> blockVector = vector<Point>(tb.WorldVector());

    vector<Point> expectedBlockVector =
            {
                    {x + 1, y - 1},
                    {x + 2, y - 1},
                    {x + 3, y - 1},
                    {x + 2, y - 2}
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