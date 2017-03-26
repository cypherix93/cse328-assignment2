#include "SphereDrawer.h"

using namespace Drawing;
using namespace std;

bool done = false;

void Drawing::DrawSphere(int depth)
{
    if (!done)
    {
        done = true;
        for (auto i = 0; i < 12; i++)
        {
            vdata[i][0] *= 2.0;
            vdata[i][1] *= 1.5;
        }
    }

    if (!glIsEnabled(GL_LIGHTING))
        glEnable(GL_LIGHTING);
    
    glBegin(GL_TRIANGLES);
    for (auto i = 0; i < 20; i++)
    {
        Subdivide(
            vdata[tindices[i][0]],
            vdata[tindices[i][1]],
            vdata[tindices[i][2]],
            depth
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

void Subdivide(float v1[3], float v2[3], float v3[3], int depth)
{
    if (depth == 0)
    {
        DrawTriangle(v1, v2, v3);
        return;
    }

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

    depth--;
    Subdivide(v1, v12, v31, depth);
    Subdivide(v2, v23, v12, depth);
    Subdivide(v3, v31, v23, depth);
    Subdivide(v12, v23, v31, depth);
}
