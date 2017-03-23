﻿#include "EventHandlers.h"
#include "../StateManager/StateManager.h"
#include "../Drawing/Cube/CubeDrawer.h"
#include "../Drawing/Tetrahedron/TetrahedronDrawer.h"

ApplicationState state;

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

    glTranslatef(0.0f, 0.0f, -8.0f);    
    glRotatef(_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(_angleY, 0.0f, 1.0f, 0.0f);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glLineWidth(4.0f);

    switch(state)
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
    auto delta = 15.0;

    if (evt.keysym.sym == SDLK_UP)
    {
        _angleX -= delta;
    }
    if (evt.keysym.sym == SDLK_DOWN)
    {
        _angleX += delta;
    }
    if (evt.keysym.sym == SDLK_LEFT)
    {
        _angleY -= delta;
    }
    if (evt.keysym.sym == SDLK_RIGHT)
    {
        _angleY += delta;
    }
    
    if (evt.keysym.sym == SDLK_1)
    {
        state = Cube;
    }
    if (evt.keysym.sym == SDLK_2)
    {
        state = Tetrahedron;
    }
}

//Called when the mouse button is pressed
void MouseButtonHandler(SDL_MouseButtonEvent evt)
{
}
