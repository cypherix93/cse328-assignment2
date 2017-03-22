#include "CubeDrawer.h"

using namespace Drawing;

void Drawing::DrawCube()
{
    glBegin(GL_LINES);

    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glVertex3f(-1.5f, 1.0f, 1.5f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glVertex3f(-1.5f, 1.0f, 1.5f);

    //Right
    //glNormal3f(1.0f, 0.0f, 0.0f);
    ////glNormal3f(1.0f, 0.0f, -1.0f);
    //glVertex3f(1.5f, -1.0f, -1.5f);
    ////glNormal3f(1.0f, 0.0f, -1.0f);
    //glVertex3f(1.5f, 1.0f, -1.5f);
    ////glNormal3f(1.0f, 0.0f, 1.0f);
    //glVertex3f(1.5f, 1.0f, 1.5f);
    ////glNormal3f(1.0f, 0.0f, 1.0f);
    //glVertex3f(1.5f, -1.0f, 1.5f);

    ////Back
    //glNormal3f(0.0f, 0.0f, -1.0f);
    ////glNormal3f(-1.0f, 0.0f, -1.0f);
    //glVertex3f(-1.5f, -1.0f, -1.5f);
    ////glNormal3f(-1.0f, 0.0f, -1.0f);
    //glVertex3f(-1.5f, 1.0f, -1.5f);
    ////glNormal3f(1.0f, 0.0f, -1.0f);
    //glVertex3f(1.5f, 1.0f, -1.5f);
    ////glNormal3f(1.0f, 0.0f, -1.0f);
    //glVertex3f(1.5f, -1.0f, -1.5f);

    ////Left
    //glNormal3f(-1.0f, 0.0f, 0.0f);
    ////glNormal3f(-1.0f, 0.0f, -1.0f);
    //glVertex3f(-1.5f, -1.0f, -1.5f);
    ////glNormal3f(-1.0f, 0.0f, 1.0f);
    //glVertex3f(-1.5f, -1.0f, 1.5f);
    ////glNormal3f(-1.0f, 0.0f, 1.0f);
    //glVertex3f(-1.5f, 1.0f, 1.5f);
    ////glNormal3f(-1.0f, 0.0f, -1.0f);
    //glVertex3f(-1.5f, 1.0f, -1.5f);

    glEnd();
}
