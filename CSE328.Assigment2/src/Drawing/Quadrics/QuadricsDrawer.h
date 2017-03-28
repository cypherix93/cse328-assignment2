#pragma once
#include "GL/freeglut.h"

enum Quadric
{
    Q_SPHERE,
    Q_CYLINDER,
    Q_CONE
};

namespace Drawing
{
    void DrawQuadrics(Quadric quadricToDraw);
}

void Init();