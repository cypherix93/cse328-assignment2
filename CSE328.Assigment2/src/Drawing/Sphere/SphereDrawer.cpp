#include "SphereDrawer.h"

using namespace Drawing;

#define X .525731112119133606
#define Z .850650808352039932

static GLfloat vdata[12][3] = {
    { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z },
    { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X },
    { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 }
};

static GLint tindices[20][3] = {
    {1,4,0}, {4,9,0}, {4,5,9}, {8,5,4}, {1,8,4},
    {1,10,8}, {10,3,8}, {8,3,5}, {3,2,5}, {3,7,2},
    {3,10,7}, {10,6,7}, {6,11,7}, {6,0,11}, {6,1,0},
    {10,1,6}, {11,0,9}, {2,11,9}, {5,2,9}, {11,2,7}
};

void Drawing::DrawSphere()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glBegin(GL_TRIANGLES);
    for (auto i = 0; i < 20; i++)
    {
        glNormal3fv(vdata[tindices[i][0]]);
        glVertex3fv(vdata[tindices[i][0]]);

        glNormal3fv(vdata[tindices[i][1]]);
        glVertex3fv(vdata[tindices[i][1]]);

        glNormal3fv(vdata[tindices[i][2]]);
        glVertex3fv(vdata[tindices[i][2]]);
    }
    glEnd();
}