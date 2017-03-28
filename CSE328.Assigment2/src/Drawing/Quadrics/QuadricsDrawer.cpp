#include "QuadricsDrawer.h"

using namespace Drawing;
using namespace std;

static bool isInited = false;

static int startList;

void Drawing::DrawQuadrics(Quadric quadricToDraw)
{
    if (!isInited)
        Init();

    if (!glIsEnabled(GL_LIGHTING))
        glEnable(GL_LIGHTING);

    glPushMatrix();

    int q = quadricToDraw;
    glCallList(startList + q);

    glPopMatrix();
    glFlush();
}

void Init()
{
    isInited = true;

    startList = glGenLists(4);
    auto quadric = gluNewQuadric();

    // Sphere
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glNewList(startList, GL_COMPILE);
    gluSphere(quadric, 1.5, 15, 10);
    glEndList();

    // Cylinder
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_FLAT);
    glNewList(startList + 1, GL_COMPILE);
    gluCylinder(quadric, 1.0, 1.0, 4.0, 15, 10);
    glEndList();

    // Cone
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_FLAT);
    glNewList(startList + 2, GL_COMPILE);
    gluCylinder(quadric, 1.0, 0.0, 4.0, 15, 10);
    glEndList();
}
