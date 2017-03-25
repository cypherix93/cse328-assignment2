#include "CubeDrawer.h"

using namespace Drawing;

static void DrawFaceAtZ(float);

void Drawing::DrawCube()
{
    glDisable(GL_LIGHTING);

    glBegin(GL_LINES);

    // Front Face
    glNormal3f(0.0f, 0.0f, 1.0f);
    DrawFaceAtZ(1.0f);

    // Back Face
    glNormal3f(0.0f, 0.0f, -1.0f);
    DrawFaceAtZ(-1.0f);

    // Right Arms
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Left Arms
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();
}

void DrawFaceAtZ(float z)
{
    glVertex3f(-1.0f, -1.0f, z);
    glVertex3f(1.0f, -1.0f, z);
    glVertex3f(1.0f, 1.0f, z);
    glVertex3f(-1.0f, 1.0f, z);

    glVertex3f(-1.0f, -1.0f, z);
    glVertex3f(-1.0f, 1.0f, z);
    glVertex3f(1.0f, 1.0f, z);
    glVertex3f(1.0f, -1.0f, z);
}