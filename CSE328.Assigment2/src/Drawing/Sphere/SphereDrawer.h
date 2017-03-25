#pragma once
#include "GL/freeglut.h"
#include <cmath>

namespace Drawing
{
    void DrawSphere();
}

static void NormalizeVector(float v[3]);
static void NormalizedCrossProduct(float v1[3], float v2[3], float out[3]);

static void DrawTriangle(float v1[3], float v2[3], float v3[3]);
static void Subdivide(float v1[3], float v2[3], float v3[3]);
