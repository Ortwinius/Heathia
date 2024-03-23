#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
    EntityVec m_entities;
    EntityVec m_toAdd;
    EntityMap m_entityMap;
    size_t    m_totalEntities = 0;

    void RemoveDeadEntities(EntityVec& vec);

public:
    EntityManager();
    void Update();
    void RenderEntities();

    std::shared_ptr<Entity> AddEntity(const std::string& tag);

    EntityVec& GetEntities();
    EntityVec& GetEntities(const std::string& tag);
    const std::map<std::string, EntityVec>& GetEntityMap();
};