﻿#include "EventHandlers.h"
#include "../StateManager/StateManager.h"
#include "../Drawing/Cube/CubeDrawer.h"
#include "../Drawing/Tetrahedron/TetrahedronDrawer.h"

ApplicationState state;

float _zoom = -12.0;
float _angleX = 0.0;
float _angleY = 0.0;

/* Event Handlers*/
void InitHandler()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 1.0, 200.0);

    state = Cube;
    _angleX = 30.0;
    _angleY = 30.0;
}

void DrawHandler()
{
    glClearColor(0.0f, 0.15f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, _zoom);
    glRotatef(_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(_angleY, 0.0f, 1.0f, 0.0f);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glLineWidth(4.0f);

    switch (state)
    {
        case Cube:
            Drawing::DrawCube();
            break;
        case Tetrahedron:
            Drawing::DrawTetrahedron();
            break;
        default:
            break;
    }
}

// Called when a keyboard key is pressed
void KeyboardButtonHandler(SDL_KeyboardEvent evt)
{
    auto key = evt.keysym.sym;
    RotationHandler(key);
    ZoomHandler(key);
    StateHandler(key);
}

//Called when the mouse button is pressed
void MouseButtonHandler(SDL_MouseButtonEvent evt)
{
}


/* Helpers */
void RotationHandler(SDL_Keycode key)
{
    auto delta = 15.0;

    if (key == SDLK_UP)
    {
        _angleX -= delta;
    }
    if (key == SDLK_DOWN)
    {
        _angleX += delta;
    }
    if (key == SDLK_LEFT)
    {
        _angleY -= delta;
    }
    if (key == SDLK_RIGHT)
    {
        _angleY += delta;
    }
}
void ZoomHandler(SDL_Keycode key)
{
    auto delta = 1.0;

    if (key == SDLK_KP_PLUS)
    {
        _zoom += delta;
    }
    if (key == SDLK_KP_MINUS)
    {
        _zoom -= delta;
    }
}
void StateHandler(SDL_Keycode key)
{
    if (key == SDLK_1)
    {
        state = Cube;
    }
    if (key == SDLK_2)
    {
        state = Tetrahedron;
    }
    if (key == SDLK_3)
    {
        state = Sphere;
    }
    if (key == SDLK_4)
    {
        state = Quadrics;
    }
}