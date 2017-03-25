#pragma once

enum ApplicationState
{
    Cube,
    Tetrahedron
};

class StateManager
{
    public:
    StateManager();
    ~StateManager();

    ApplicationState State;
};

