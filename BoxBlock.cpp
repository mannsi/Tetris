#include "BoxBlock.h"

using namespace std;


BoxBlock::BoxBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(0,1,0)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.nextPointXOffset = -1;
    form1.nextPointYOffset = -1;
    form1.form.push_back({true});
    form1.form.push_back({true});
    form1.form.push_back({true});
    form1.form.push_back({true});
    _forms.push_back(form1);

    BlockForm form2 = BlockForm();
    form2.nextPointXOffset = 1;
    form2.nextPointYOffset = 1;
    form2.form.push_back({true, true, true, true});
    _forms.push_back(form2);
}
