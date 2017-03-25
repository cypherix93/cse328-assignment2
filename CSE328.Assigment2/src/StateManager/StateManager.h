#pragma once

enum ApplicationState
{
    Cube,
    Tetrahedron,
    Sphere,
    Quadrics
};

class StateManager
{
    public:
    StateManager();
    ~StateManager();

    ApplicationState State;
};

