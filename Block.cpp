#include "Block.h"

void Block::MoveDown() {
    // Move all points in _worldVector down (-1 on all Y values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point* currentPoint = _worldVector[i];
        currentPoint->Y -= 1;
    }
}

void Block::MoveRight() {
    // Move all points in _worldVector right (+1 on all X values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point* currentPoint = _worldVector[i];
        currentPoint->X += 1;
    }
}

void Block::MoveLeft() {
    // Move all points in _worldVector left (-1 on all X values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point* currentPoint = _worldVector[i];
        currentPoint->X -= 1;
    }
}
