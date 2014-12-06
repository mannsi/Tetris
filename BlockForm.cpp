#include "BlockForm.h"

using namespace std;

vector<Point>  BlockForm::_worldVector() {
    vector<Point> pointsToReturn;
    for (int i = 0; i < form.size(); ++i) {
        vector<bool> lineVector = form[i];
        for (int j = 0; j < lineVector.size(); ++j) {
            if (lineVector[j])
            {
                Point worldPoint = Point(initialPoint);
                worldPoint.X -= j;
                worldPoint.Y -= i;
                pointsToReturn.push_back(worldPoint);
            }
        }
    }
    return pointsToReturn;
}
