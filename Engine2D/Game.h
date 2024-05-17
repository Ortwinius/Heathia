#pragma once

#include <raylib.h>
//#include <imgui.h>
#include "EntityManager.h"
#include "Entity.h"
#include "Components.h"

class Game
{
private:

public:
    EntityManager m_entities;
    std::shared_ptr <Entity> m_player;
    bool m_paused;
    bool m_running;

    Game();
    void Init();
    void Run();
    void SpawnPlayer();

    // systems
    void sMovement();
    void sUserInput();
    void sRender();
    void sEnemySpawner();
    void sCollision();

    // utility
    void uResetMovementFlags();
};