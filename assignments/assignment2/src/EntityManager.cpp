#include <vector>
#include <map>
#include <memory>
#include <string>

#include "../include/Entity.h"
#include "../include/EntityManager.h"

EntityManager::EntityManager() {}

void EntityManager::update()
{
    // TODO: Add entitites from m_entitiesToAdd to the proper locations
    //       - add them to the vector of all entities
    //       - add them to the vector inside the map, with the tag as the key

    for (auto e : m_toAdd)
    {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAdd.clear();

    // remove dead entities from the vector of all entities
    removeDeadEntities(m_entities);
    
    // remove dead entities from each vector in the entity map
    for (auto& [tag, entityVec] : m_entityMap)
    {
        removeDeadEntities(entityVec);
    }
}

bool isActive(Entity& e)
{
    return e.isActive();
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
    // TODO: Remove all dead enemies

    // for (auto e : vec)
    // {
    //     if (!e->isActive())
    //     {
    //         // remove from vector
    //     }
    // }

    // std::remove_if(vec.begin(), vec.end(), [](Entity& e){return e.isActive();});

    // I think this works??
    // vec.erase(std::remove_if(vec.begin(), vec.end(), isActive), vec.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

    m_toAdd.push_back(entity);

    return entity;
}

EntityVec& EntityManager::getEntities()
{
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
    return m_entityMap[tag];
}