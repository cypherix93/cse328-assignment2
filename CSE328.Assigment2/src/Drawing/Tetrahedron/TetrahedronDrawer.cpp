#include "TetrahedronDrawer.h"

using namespace Drawing;

void Drawing::DrawTetrahedron()
{
    glBegin(GL_LINES);

    float basePoints[3][3] = {
        { -2.0f, 0.0f, 2.0f },
        { 2.0f, 0.0f, 2.0f },
        { 0.0f, 0.0f, -2.0f }
    };

    float apexPoint[3] = { 0.0f, 2.0f, 0.0f };

    // Base
    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3fv(basePoints[0]);
    glVertex3fv(basePoints[1]);
    glVertex3fv(basePoints[1]);
    glVertex3fv(basePoints[2]);
    glVertex3fv(basePoints[2]);
    glVertex3fv(basePoints[0]);

    // Top Lines
    glNormal3f(0.0f, 1.0f, 0.0f);
    
    glVertex3fv(basePoints[0]);
    glVertex3fv(apexPoint);

    glVertex3fv(basePoints[1]);
    glVertex3fv(apexPoint);

    glVertex3fv(basePoints[2]);
    glVertex3fv(apexPoint);

    glEnd();
}