#ifndef BLOCK_FORM_H
#define BLOCK_FORM_H

#include <vector>
#include "Point.h"

using namespace std;

class BlockForm
{
public:
    vector<vector<bool>> form;
    Point referencePoint;

    vector<Point> _worldVector();
};

#endif