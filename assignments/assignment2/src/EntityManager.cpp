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
    }

    m_toAdd.clear();

    // remove dead entities from the vector of all entities
    removeDeadEntities(m_entities);
    
    // remove dead entities from each vector in the entity map
    // for (auto& [tag, entityVec] : m_entityMap)
    for (auto& entityMap : m_entityMap)
    {
        removeDeadEntities(entityMap.second);
    }
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
    // TODO: Remove all dead enemies
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    auto entity = std::make_shared<Entity>(new Entity(m_totalEntities++, tag));

    m_toAdd.push_back(entity);

    return entity;
}

EntityVec& EntityManager::getEntities()
{

}

EntityVec& EntityManager::getEntities(const std::string& tag)
{

}