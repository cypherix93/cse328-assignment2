#include "SphereDrawer.h"

using namespace Drawing;

#define X .525731112119133606
#define Z .850650808352039932

static float vdata[12][3] = {
    { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z },
    { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X },
    { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 }
};

static int tindices[20][3] = {
    {1,4,0}, {4,9,0}, {4,5,9}, {8,5,4}, {1,8,4},
    {1,10,8}, {10,3,8}, {8,3,5}, {3,2,5}, {3,7,2},
    {3,10,7}, {10,6,7}, {6,11,7}, {6,0,11}, {6,1,0},
    {10,1,6}, {11,0,9}, {2,11,9}, {5,2,9}, {11,2,7}
};

void Drawing::DrawSphere()
{
    glEnable(GL_LIGHTING);

    glBegin(GL_TRIANGLES);
    for (auto i = 0; i < 20; i++)
    {
        Subdivide(
            vdata[tindices[i][0]],
            vdata[tindices[i][1]],
            vdata[tindices[i][2]]
        );
    }
    glEnd();
}

void NormalizeVector(float v[3])
{
    auto d = sqrt((v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]));

    if (d == 0.0)
        return;

    v[0] /= d;
    v[1] /= d;
    v[2] /= d;
}

void NormalizedCrossProduct(float v1[3], float v2[3], float out[3])
{
    out[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    out[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
    out[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
    NormalizeVector(out);
}

static void DrawTriangle(float v1[3], float v2[3], float v3[3])
{
    glNormal3fv(v1);
    glVertex3fv(v1);

    glNormal3fv(v2);
    glVertex3fv(v2);

    glNormal3fv(v3);
    glVertex3fv(v3);
}

void Subdivide(float v1[3], float v2[3], float v3[3])
{
    float v12[3];
    float v23[3];
    float v31[3];

    for (auto i = 0; i < 3; i++)
    {
        v12[i] = (v1[i] + v2[i]) / 2.0;
        v23[i] = (v2[i] + v3[i]) / 2.0;
        v31[i] = (v3[i] + v1[i]) / 2.0;
    }

    NormalizeVector(v12);
    NormalizeVector(v23);
    NormalizeVector(v31);

    DrawTriangle(v1, v12, v31);
    DrawTriangle(v2, v23, v12);
    DrawTriangle(v3, v31, v23);
    DrawTriangle(v12, v23, v31);
}
