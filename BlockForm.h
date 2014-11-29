#ifndef BLOCK_FORM_H
#define BLOCK_FORM_H

#include <vector>
#include "Point.h"

using namespace std;

class BlockForm
{
public:
    vector<Point> forms;
    Point nextInitPoint;
    BlockForm(Point initPoint);
};

#endif