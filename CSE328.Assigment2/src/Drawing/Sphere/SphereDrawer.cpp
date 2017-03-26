#include "SphereDrawer.h"

using namespace Drawing;
using namespace std;

vector<vector<float>> GetEllipsoidCoords(float rx, float ry = 0, float rz = 0)
{
    // If a regular sphere is asked for
    if (ry == 0.0 || rz == 0.0)
    {
        ry = rx;
        rz = rx;
    }

    float x, y, z;

    vector<vector<float>> coords;

    auto steps = 4;

    float sStart, sEnd, sDel;
    sStart = -M_PI / 2;
    sEnd = M_PI / 2;
    sDel = (sEnd - sStart) / steps;

    float tStart, tEnd, tDel;
    tStart = -M_PI;
    tEnd = M_PI;
    tDel = (tEnd - tStart) / steps;

    for (auto s = sStart; s <= sEnd; s += sDel)
    {
        for (auto t = tStart; t <= tEnd; t += tDel)
        {
            x = rx * cos(s) * cos(t);
            y = ry * cos(s) * sin(t);
            z = rz * sin(s);

            coords.push_back({ x, y, z });
        }
    }

    return coords;
}

void Drawing::DrawSphere(int depth)
{
    if (!glIsEnabled(GL_LIGHTING))
        glEnable(GL_LIGHTING);

    auto coords = GetSphereCoords(1.0);

    /*glPointSize(4.0);
    glBegin(GL_POINTS);

    glColor3f(1.0, 0.0, 0.0);
    for each (auto coord in coords)
    {
        glVertex3fv(&coord[0]);
    }

    /*glColor3f(1.0, 1.0, 1.0);
    for (auto i = 0; i < 12; i++)
    {
        glVertex3fv(vdata[i]);
    }#1#

    glEnd();*/

    glBegin(GL_TRIANGLES);
    for (auto i = 0; i < coords.size() - 2; i++)
    {
        auto v1 = coords[i];
        auto v2 = coords[i + 1];
        auto v3 = coords[i + 2];

        Subdivide(
            &v1[0],
            &v2[0],
            &v3[0],
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
