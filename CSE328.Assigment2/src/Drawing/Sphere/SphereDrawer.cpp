#include "SphereDrawer.h"

using namespace Drawing;
using namespace std;

void Drawing::DrawSphere(float r, int depth)
{
    DrawGeneralEllipsoid(r, r, r, depth);
}
