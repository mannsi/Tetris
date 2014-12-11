#include "Block.h"

void Block::MoveDown() {
    // Move the current forms reference point down by one
    _forms[_currentFormIndex].referencePoint.Y -= 1;
}

void Block::MoveRight() {
    // Move the current forms reference point to the right by one
    _forms[_currentFormIndex].referencePoint.X += 1;
}

void Block::MoveLeft() {
    // Move the current forms reference point to the left by one
    _forms[_currentFormIndex].referencePoint.X -= 1;
}

void Block::Turn(){
    BlockForm& currentForm = _forms[_currentFormIndex];

    _currentFormIndex++;
    if (_currentFormIndex == _forms.size())
    {
        _currentFormIndex = 0;
    }

    BlockForm& nextForm = _forms[_currentFormIndex];

    nextForm.referencePoint = Point(currentForm.referencePoint);
}

vector<Point> Block::WorldVector() {
    return _forms[_currentFormIndex]._worldVector();
}
