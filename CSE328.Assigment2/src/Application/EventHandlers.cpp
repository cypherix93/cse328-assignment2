#include "EventHandlers.h"

static ApplicationState state;

static float _zoom = -8.0;
static float _angleX = 30.0;
static float _angleY = 30.0;

static int _sphereDepth = 0;
static Quadric _quadricToDraw = Q_SPHERE;

/* Event Handlers*/
void InitHandler()
{
    float matAmbient[] = { 0.5, 0.5, 0.5, 1.0 };
    float matSpecular[] = { 0.5, 0.5, 0.5, 1.0 };
    float matShininess[] = { 20.0 };
    float lightPosition[] = { -5.0, 5.0, 1.0, 1.0 };
    float modelAmbient[] = { 0.5, 0.5, 0.5, 1.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmbient);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 1.0, 200.0);

    state = Cube;
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
        case Sphere:
            Drawing::DrawSphere(1.0, _sphereDepth);
            break;
        case Quadrics:
            Drawing::DrawQuadrics(_quadricToDraw);
            break;
        case Ellipsoid:
            Drawing::DrawEllipsoid(2.0, 1.5, 1.0, _sphereDepth);
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
    if (state == Sphere || state == Ellipsoid)
    {
        if (evt.button == SDL_BUTTON_LEFT)
        {
            if (_sphereDepth < 2)
                _sphereDepth++;
        }
        if (evt.button == SDL_BUTTON_RIGHT)
        {
            if (_sphereDepth > 0)
                _sphereDepth--;
        }
    }
    if (state == Quadrics)
    {
        int q = _quadricToDraw;

        if (evt.button == SDL_BUTTON_LEFT)
        {
            q++;
            if (q > 2)
                q = 0;
        }
        if (evt.button == SDL_BUTTON_RIGHT)
        {
            q--;
            if (q < 0)
                q = 2;
        }

        _quadricToDraw = static_cast<Quadric>(q);
    }
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

    if (_angleX < 0.0)
        _angleX += 360.0;
    if (_angleY < 0.0)
        _angleY += 360.0;

    if (_angleX >= 360.0)
        _angleX -= 360.0;
    if (_angleY >= 360.0)
        _angleY -= 360.0;
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

    if (_zoom < -50.0)
        _zoom = -50.0;

    if (_zoom > -4.0)
        _zoom = -4.0;
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
    if (key == SDLK_5)
    {
        state = Ellipsoid;
    }
}