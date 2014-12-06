#ifndef POINT_H
#define POINT_H

struct Point
{
    bool operator==(const Point& rhs)
    {
        return (X == rhs.X && Y == rhs.Y);
    }

    int X;
    int Y;
};

#endif