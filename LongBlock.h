#ifndef LONGBLOCK_H
#define LONGBLOCK_H

#include "Block.h"

class LongBlock: public Block
{
public:
    LongBlock(Point initial_top_left_world_point);

    virtual void TurnLeft();
    virtual void TurnRight();
};

#endif