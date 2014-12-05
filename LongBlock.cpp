#include "LongBlock.h"

using namespace std;


LongBlock::LongBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(1,0,0)) {

    BlockForm* form1 = new BlockForm();
    form1->initialPoint = initial_top_left_world_point;
    form1->nextPointXOffset = -1;
    form1->nextPointYOffset = -1;
    form1->form.push_back({true});
    form1->form.push_back({true});
    form1->form.push_back({true});
    form1->form.push_back({true});
    _forms.push_back(form1);

    BlockForm* form2 = new BlockForm();
    form2->nextPointXOffset = 1;
    form2->nextPointYOffset = 1;
    form2->form.push_back({true, true, true, true});
    _forms.push_back(form2);
}
