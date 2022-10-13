#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "EntityManager.h"
#include "Entity.h"

class Game
{
    sf::RenderWindow m_window;
    EntityManager    m_entities;
    sf::Font         m_font;
    sf::Text         m_text;
    // PlayerConfig, EnemyConfig, BulletConfig
    int              m_score              = 0;
    int              m_currentFrame       = 0;
    int              m_lastEnemySpawnTime = 0;
    bool             m_paused  = false;
    bool             m_running = true;

    std::shared_ptr<Entity> m_player;

    void init(const std::string& config);
    void setPaused(bool paused);

    void sMovement();
    void sUserInput();
    void sLifespan();
    void sRender();
    void sEnemySpawner();
    void sCollision();

    void spawnPlayer();
    void spawnEnemy();
    void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
    void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:
    Game(const std::string& config);

    void run();
};

#endif