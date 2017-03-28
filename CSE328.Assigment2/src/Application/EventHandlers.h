#pragma once
#include "Application.h"

#include "../StateManager/StateManager.h"
#include "../Drawing/Cube/CubeDrawer.h"
#include "../Drawing/Tetrahedron/TetrahedronDrawer.h"
#include "../Drawing/Sphere/SphereDrawer.h"
#include "../Drawing/Quadrics/QuadricsDrawer.h"
#include "../Drawing/Ellipsoid/EllipsoidDrawer.h"

using namespace std;

void InitHandler();
void DrawHandler();
void KeyboardButtonHandler(SDL_KeyboardEvent);
void MouseButtonHandler(SDL_MouseButtonEvent);


void RotationHandler(SDL_Keycode key);
void ZoomHandler(SDL_Keycode key);
void StateHandler(SDL_Keycode key);