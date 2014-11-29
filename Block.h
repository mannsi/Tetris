#ifndef BLOCK_H
#define BLOCK_H

#include "Color.h"
#include "BlockForm.h"
#include "Point.h"
#include <vector>

class Block
{
protected:
    vector<Point*> _worldVector;
    vector<BlockForm*> _forms;

public:
    int _initialHeight;
    int _initialWidth;
    Color _color;

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    virtual void TurnLeft() = 0;
    virtual void TurnRight() = 0;

};

#endif