#pragma once
#include "GL/freeglut.h"
#include <cmath>
#include <array>

using namespace std;

#define X .525731112119133606
#define Z .850650808352039932

static array<array<float, 3>, 12> VERTICES = { {
    { -X, 0.0, Z },{ X, 0.0, Z },{ -X, 0.0, -Z },{ X, 0.0, -Z },
    { 0.0, Z, X },{ 0.0, Z, -X },{ 0.0, -Z, X },{ 0.0, -Z, -X },
    { Z, X, 0.0 },{ -Z, X, 0.0 },{ Z, -X, 0.0 },{ -Z, -X, 0.0 }
} };

static array<array<float, 3>, 20> TRIANGLE_INDICES = { {
    { 1,4,0 },{ 4,9,0 },{ 4,5,9 },{ 8,5,4 },{ 1,8,4 },
    { 1,10,8 },{ 10,3,8 },{ 8,3,5 },{ 3,2,5 },{ 3,7,2 },
    { 3,10,7 },{ 10,6,7 },{ 6,11,7 },{ 6,0,11 },{ 6,1,0 },
    { 10,1,6 },{ 11,0,9 },{ 2,11,9 },{ 5,2,9 },{ 11,2,7 }
} };

void DrawGeneralEllipsoid(float rx, float ry, float rz, int depth = 0);

static void Subdivide(float v1[3], float v2[3], float v3[3], float rx, float ry, float rz, int depth = 0);

static void GetIntersection(float v[3], float rx, float ry, float rz);
static void DrawTriangle(float v1[3], float v2[3], float v3[3]);
