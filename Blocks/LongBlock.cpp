#include "LongBlock.h"

using namespace std;


LongBlock::LongBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(1,0,0)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.form.push_back({false, false, true, false});
    form1.form.push_back({false, false, true, false});
    form1.form.push_back({false, false, true, false});
    form1.form.push_back({false, false, true, false});
    _forms.push_back(form1);

    BlockForm form2 = BlockForm();
    form2.form.push_back({false, false, false, false});
    form2.form.push_back({true, true, true, true});
    form2.form.push_back({false, false, false, false});
    form2.form.push_back({false, false, false, false});
    _forms.push_back(form2);
}
