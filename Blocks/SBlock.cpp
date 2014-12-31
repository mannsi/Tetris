#include "SBlock.h"

using namespace std;


SBlock::SBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(0,1,1)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.form.push_back({false, false, false, false});
    form1.form.push_back({false, false, true, true});
    form1.form.push_back({false, true, true, false});
    form1.form.push_back({false, false, false, false});
    _forms.push_back(form1);

    BlockForm form2 = BlockForm();
    form2.form.push_back({false, false, true, false});
    form2.form.push_back({false, false, true, true});
    form2.form.push_back({false, false, false, true});
    form2.form.push_back({false, false, false, false});
    _forms.push_back(form2);
}
