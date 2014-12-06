#include "Block.h"

void Block::MoveDown() {
    // Move all points in _worldVector down (-1 on all Y values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point& currentPoint = _worldVector[i]; // Use Point reference
        currentPoint.Y -= 1;
    }
}

void Block::MoveRight() {
    // Move all points in _worldVector right (+1 on all X values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point& currentPoint = _worldVector[i]; // Use Point reference
        currentPoint.X += 1;
    }
}

void Block::MoveLeft() {
    // Move all points in _worldVector left (-1 on all X values)
    for (int i = 0; i < _worldVector.size(); ++i) {
        Point& currentPoint = _worldVector[i]; // Use Point reference
        currentPoint.X -= 1;
    }
}

void Block::Turn(){
    BlockForm& currentForm = _forms[_currentFormIndex];

    _currentFormIndex++;
    if (_currentFormIndex == _forms.size())
    {
        _currentFormIndex = 0;
    }

    BlockForm& nextForm = _forms[_currentFormIndex];

    Point nextInitialPoint = currentForm.initialPoint;
    nextInitialPoint.X += currentForm.nextPointXOffset;
    nextInitialPoint.Y += currentForm.nextPointYOffset;
    nextForm.initialPoint = nextInitialPoint;
}

vector<Point> Block::WorldVector() {
    return _forms[_currentFormIndex]._worldVector();
}
