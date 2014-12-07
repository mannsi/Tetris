#include "BoxBlock.h"

using namespace std;


BoxBlock::BoxBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(0,1,0)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.nextPointXOffset = 0;
    form1.nextPointYOffset = 0;
    form1.form.push_back({true, true});
    form1.form.push_back({true, true});
    _forms.push_back(form1);
}
