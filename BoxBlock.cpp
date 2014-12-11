#include "BoxBlock.h"

using namespace std;


BoxBlock::BoxBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(0,1,0)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.form.push_back({false, false, false, false});
    form1.form.push_back({false, true, true, false});
    form1.form.push_back({false, true, true, false});
    form1.form.push_back({false, false, false, false});
    _forms.push_back(form1);
}
