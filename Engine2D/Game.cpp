#include "Game.h"

Game::Game()
{
    m_paused = false;
    m_running = true;
}

void Game::Init()
{
    InitWindow(640, 480, "Engine");
    SetTargetFPS(60);

    // spawn player
    SpawnPlayer();

}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        // update the entity manager
        m_entities.Update();

        // TODO: add gui update function
        
        // sEnemySpawner();
        // sMovement();
        // sCollision();
        // sUserInput();

        BeginDrawing();
        // sGUI();
        sRender();
        EndDrawing();
    }
}

void Game::SpawnPlayer()
{
    auto e = m_entities.AddEntity("player");
    e->cTransform = std::make_shared<CTransform>(Vector2(200.0f, 200.0f), Vector2(1.0f, 1.0f), Vector2(1.0f, 1.0f), 0.0f);
    e->cShape = std::make_shared<CShape>(Vector2(200.0f, 200.0f), Vector2(100.0f, 100.0f));
    e->cBoundingBox = std::make_shared<CBoundingBox>(Vector2(100.0f, 100.0f));
    e->cInput = std::make_shared<CInput>();
}

void Game::sMovement()
{

}

void Game::sUserInput()
{

}

void Game::sRender()
{
    m_entities.RenderEntities();
}

void Game::sEnemySpawner()
{
    // create enemy
    auto e = m_entities.AddEntity("enemy");
    e->cTransform = std::make_shared<CTransform>(Vector2(200.0f, 200.0f), Vector2(100.0f, 100.0f), Vector2(1.0f, 1.0f), 0.0f);
    e->cShape = std::make_shared<CShape>(e->cTransform->m_position, e->cTransform->m_scale);
    e->cBoundingBox = std::make_shared<CBoundingBox>(Vector2(100.0f, 100.0f));
}

void Game::sCollision()
{
}
