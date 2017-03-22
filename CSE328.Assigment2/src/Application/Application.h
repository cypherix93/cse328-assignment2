#pragma once
#include <iostream>
#include <vector>
#include "../WindowManager/WindowManager.h"
#include <SDL.h>
#include <GL/freeglut.h>
#include "../Drawing/Cube/CubeDrawer.h"

using namespace std;
using namespace Drawing;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Application
{
    public:
    Application();
    virtual ~Application();

    // Lifecycle Hooks
    void Setup();
    void Start();

    private:
    WindowManager* _WindowManager;
};

void InitHandler();
void DrawHandler();
void KeyboardButtonHandler(SDL_KeyboardEvent);
void MouseButtonHandler(SDL_MouseButtonEvent);