#include <iostream>
#include <fstream>
#include <string>

#include "../include/Game.h"
#include "../include/Entity.h"
#include "../include/EntityManager.h"
#include "../include/Vec2.h"

Game::Game(const std::string& configFile)
{
    init(configFile);
}

void Game::run()
{
    // TODO: Update systems correctly when paused (add pause functionality)

    while (m_running)
    {
        m_entities.update();

        sEnemySpawner();
        sMovement();
        sCollision();
        sUserInput();
        sRender();

        m_currentFrame++; // need to move when paused
    }
}

void Game::init(const std::string& configFile)
{
    // TODO: Load in variables from a config file

    // create window
    m_window.create(sf::VideoMode(1600, 900), "Assignment 2");
    m_window.setFramerateLimit(60);

    spawnPlayer();
}

void Game::setPaused(bool paused)
{
    m_paused = paused;
}

// TODO: Define systems
void Game::sMovement()
{
    // player movement
    m_player->cTransform->vel = {0.0f, 0.0f};
    const float player_speed = 5.0f;

    if (m_player->cInput->up)
    {
        m_player->cTransform->vel.y += player_speed;
    }

    if (m_player->cInput->left)
    {
        m_player->cTransform->vel.x -= player_speed;
    }

    if (m_player->cInput->down)
    {
        m_player->cTransform->vel.y -= player_speed;
    }

    if (m_player->cInput->right)
    {
        m_player->cTransform->vel.x += player_speed;
    }

    for (auto& e : m_entities.getEntities())
    {
        e->cTransform->vel.y *= -1.0f;
        e->cTransform->pos += e->cTransform->vel;
    }
}

void Game::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // end game
        if (event.type == sf::Event::Closed)
            m_running = false;
        
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    m_player->cInput->up = true;
                    break;
                
                case sf::Keyboard::A:
                    m_player->cInput->left = true;
                    break;

                case sf::Keyboard::S:
                    m_player->cInput->down = true;
                    break;

                case sf::Keyboard::D:
                    m_player->cInput->right = true;
                    break;

                case sf::Keyboard::Escape:
                    m_running = false;
                    break;

                default: break;
            }
        }

        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    m_player->cInput->up = false;
                    break;
                
                case sf::Keyboard::A:
                    m_player->cInput->left = false;
                    break;

                case sf::Keyboard::S:
                    m_player->cInput->down = false;
                    break;

                case sf::Keyboard::D:
                    m_player->cInput->right = false;
                    break;

                default: break;
            }
        }
    }
}

void Game::sLifespan()
{

}

void Game::sRender()
{
    m_window.clear();

    // m_window.draw(m_player->cShape->circle);
    for (auto& e : m_entities.getEntities())
    {
        e->cShape->circle.setPosition(
            e->cTransform->pos.x, e->cTransform->pos.y);
        
        m_window.draw(e->cShape->circle);
    }

    m_window.display();
}

void Game::sEnemySpawner()
{

}

void Game::sCollision()
{

}


void Game::spawnPlayer()
{
    // TODO: Finish adding all properties of the player with the correct values 
    //       from the config 

    // create player entity
    auto entity = m_entities.addEntity("Player");

    // define components in player entity
    entity->cTransform = std::make_shared<CTransform>(
        Vec2(100.0f, 100.0f), 
        Vec2(1.0f, 1.0f), 
        0.0f
    );

    entity->cShape = std::make_shared<CShape>(
        32.0f, 
        8, 
        sf::Color(10, 10, 10), 
        sf::Color(255, 0, 0), 
        4.0f
    );

    entity->cInput = std::make_shared<CInput>();

    // set player to the created entity (only because we use this so much)
    m_player = entity;
}

void Game::spawnEnemy()
{
    // TODO: Make sure the enemy is spawned properly with the config variables
    //       make sure enemy is spawned COMPLETELY WITHIN the window

    auto entity = m_entities.addEntity("Enemy");

    float ex = rand() % m_window.getSize().x;
    float ey = rand() % m_window.getSize().y;

    entity->cTransform = std::make_shared<CTransform>(
        Vec2(ex, ey),
        Vec2(0.0f, 0.0f),
        0.0f      
    );

    entity->cShape = std::make_shared<CShape>(
        16.0f,
        3, 
        sf::Color(0, 0, 255),
        sf::Color(255, 255, 255),
        4.0f
    );

    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity)
{

}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}