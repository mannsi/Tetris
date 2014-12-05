#ifndef BLOCK_H
#define BLOCK_H

#include "Color.h"
#include "BlockForm.h"
#include "Point.h"
#include <vector>

class Block
{
protected:
    vector<Point*> _worldVector; // The world point of the block at each time
    vector<BlockForm*> _forms; // All the different forms of the block.
    int _currentFormIndex;
    Block(Point initialPoint, Color color) : _initialPoint(initialPoint), _color(color)
    {
        _currentFormIndex = 0;
    }

public:
    Point _initialPoint;
    Color _color;

    vector<Point*> WorldVector();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void Turn();


};

#endif