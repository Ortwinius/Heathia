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
        // sCollision();
        sUserInput();
        sMovement();

        BeginDrawing();
        // sGUI();
        ClearBackground(BLACK);
        sRender();
        EndDrawing();
    }
}

void Game::SpawnPlayer()
{
    m_player = m_entities.AddEntity("player");
    m_player->cTransform = std::make_shared<CTransform>(Vector2(200.0f, 200.0f), Vector2(1.0f, 1.0f), Vector2(1.0f, 1.0f), 0.0f);
    m_player->cShape = std::make_shared<CShape>(Vector2(100.0f, 100.0f));
    m_player->cBoundingBox = std::make_shared<CBoundingBox>(Vector2(100.0f, 100.0f));
    m_player->cInput = std::make_shared<CInput>();
}

void Game::sUserInput()
{
    if(IsKeyPressed(KEY_ESCAPE))
	{
		m_running = false;
	}
    if (IsKeyPressed(KEY_P))
    {
        m_paused = !m_paused;
    }
    if(IsKeyDown(KEY_W))
    {
        m_player->cInput->up = true;
	}
	if(IsKeyDown(KEY_S))
	{
		m_player->cInput->down = true;
	}
	if(IsKeyDown(KEY_A))
	{
		m_player->cInput->left = true;
	}
}

// movement system for player entity only
void Game::sMovement()
{
    //uResetMovementFlags(); // reset movement every frame

    if (m_player && m_player->cInput) {
        if (IsKeyDown(KEY_W)) {
            m_player->cTransform->m_position.y -= 1.0f;
        }
        if (IsKeyDown(KEY_S)) {
            m_player->cTransform->m_position.y += 1.0f;
        }
        if (IsKeyDown(KEY_A)) {
            m_player->cTransform->m_position.x -= 1.0f;
        }
        if (IsKeyDown(KEY_D)) {
            m_player->cTransform->m_position.x += 1.0f;
        }
    }
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
    e->cShape = std::make_shared<CShape>(e->cTransform->m_scale);
    e->cBoundingBox = std::make_shared<CBoundingBox>(Vector2(100.0f, 100.0f));
}

void Game::sCollision()
{
}

void Game::uResetMovementFlags()
{
    if (m_player)
    {
        m_player->cInput->up = false;
        m_player->cInput->down = false;
        m_player->cInput->left = false;
        m_player->cInput->right = false;
    }
}
