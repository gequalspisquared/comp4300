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
    spawnPlayer();

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
    m_window.create(sf::VideoMode(800, 600), "Assignment 2");
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

}

void Game::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // end game
        if (event.type == sf::Event::Closed)
            m_running = false;
    }
}

void Game::sLifespan()
{

}

void Game::sRender()
{
    m_window.clear();

    m_window.draw(m_player->cShape->circle);

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
        Vec2(200.0f, 200.0f), 
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