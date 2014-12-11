#include "JBlock.h"

using namespace std;


JBlock::JBlock(Point initial_top_left_world_point): Block(initial_top_left_world_point, Color(1,0,1)) {

    BlockForm form1 = BlockForm();
    form1.referencePoint = initial_top_left_world_point;
    form1.form.push_back({false, false, false, false});
    form1.form.push_back({false, true, true, true});
    form1.form.push_back({false, false, false, true});
    form1.form.push_back({false, false, false, false});
    _forms.push_back(form1);

    BlockForm form2 = BlockForm();
    form2.form.push_back({false, false, true, true});
    form2.form.push_back({false, false, true, false});
    form2.form.push_back({false, false, true, false});
    form2.form.push_back({false, false, false, false});
    _forms.push_back(form2);

    BlockForm form3 = BlockForm();
    form3.form.push_back({false, true, false, false});
    form3.form.push_back({false, true, true, true});
    form3.form.push_back({false, false, false, false});
    form3.form.push_back({false, false, false, false});
    _forms.push_back(form3);

    BlockForm form4 = BlockForm();
    form4.form.push_back({false, false, true, false});
    form4.form.push_back({false, false, true, false});
    form4.form.push_back({false, true, true, false});
    form4.form.push_back({false, false, false, false});
    _forms.push_back(form4);
}
