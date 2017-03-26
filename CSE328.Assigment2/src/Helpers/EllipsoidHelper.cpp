#include "EllipsoidHelper.h"

using namespace std;

void DrawGeneralEllipsoid(float rx, float ry, float rz, int depth)
{
    auto vdata = VERTICES;
    auto tindices = TRIANGLE_INDICES;

    for (auto i = 0; i < 12; i++)
    {
        vdata[i][0] *= rx;
        vdata[i][1] *= ry;
        vdata[i][2] *= rz;
    }

    if (!glIsEnabled(GL_LIGHTING))
        glEnable(GL_LIGHTING);

    glBegin(GL_TRIANGLES);
    for (auto i = 0; i < 20; i++)
    {
        auto v1 = vdata[tindices[i][0]];
        auto v2 = vdata[tindices[i][1]];
        auto v3 = vdata[tindices[i][2]];

        Subdivide(&v1[0], &v2[0], &v3[0], rx, ry, rz, depth);
    }
    glEnd();
}

static void Subdivide(float v1[3], float v2[3], float v3[3], float rx, float ry, float rz, int depth)
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

    GetIntersection(v12, rx, ry, rz);
    GetIntersection(v23, rx, ry, rz);
    GetIntersection(v31, rx, ry, rz);

    depth--;
    Subdivide(v1, v12, v31, rx, ry, rz, depth);
    Subdivide(v2, v23, v12, rx, ry, rz, depth);
    Subdivide(v3, v31, v23, rx, ry, rz, depth);
    Subdivide(v12, v23, v31, rx, ry, rz, depth);
}


static void GetIntersection(float v[3], float rx, float ry, float rz)
{
    auto rx2 = rx * rx;
    auto ry2 = ry * ry;
    auto rz2 = rz * rz;

    auto x2 = v[0] * v[0];
    auto y2 = v[1] * v[1];
    auto z2 = v[2] * v[2];

    auto denom = (x2 * ry2 * rz2) + (y2 * rx2 * rz2) + (z2 * ry2 * rx2);

    auto t = (rx * ry * rz) / sqrt(denom);

    v[0] = t * v[0];
    v[1] = t * v[1];
    v[2] = t * v[2];
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