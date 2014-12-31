#ifndef BLOCK_FORM_H
#define BLOCK_FORM_H

#include <vector>
#include "Point.h"

using namespace std;

/*
Represents the state of a single block. Each block has a list of BlockForm's
that it cycles through when the block turns.
 */
class BlockForm
{
public:
    vector<vector<bool>> form;
    Point referencePoint;

    vector<Point> _worldVector();
};

#endif