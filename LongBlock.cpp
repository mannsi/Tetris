#include "LongBlock.h"

using namespace std;


LongBlock::LongBlock(Point initial_top_left_world_point) {
    // Here we create a long block

    _initialHeight = 4;
    _initialWidth = 1;
    _color = Color(1, 0, 0); // RED

    // Set _forms
    BlockForm* form1 = new BlockForm();
    form1->forms.push_back({true});
    form1->forms.push_back({true});
    form1->forms.push_back({true});
    form1->forms.push_back({true});
    _forms.push_back(form1);

    BlockForm* form2 = new BlockForm();
    form2->forms.push_back({true, true, true, true});
    _forms.push_back(form2);

    // Set _worldVector points
    Point initPoint = initial_top_left_world_point;
    _worldVector.push_back(&initPoint);

    Point point2 = Point(initPoint);
    point2.Y = point2.Y - 1;
    _worldVector.push_back(&point2);

    Point point3 = Point(initPoint);
    point3.Y -= 2;
    _worldVector.push_back(&point3);

    Point point4 = Point(initPoint);
    point4.Y -= 3;
    _worldVector.push_back(&point4);
}

void LongBlock::TurnLeft() {
}

void LongBlock::TurnRight() {
}