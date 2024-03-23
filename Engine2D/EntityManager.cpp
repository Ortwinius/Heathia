#include "EntityManager.h"

void EntityManager::RemoveDeadEntities(EntityVec& vec)
{
	// if e is dead remove it from m_entities and m_entityMap[e->tag()]

	// TODO: create temporary Vec toDelete, push all the entities to remove and then remove them one by one

	for (auto e : m_entities)
	{
		if (!e->IsAlive())
		{
			m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), e));
			m_entityMap.erase(e->Tag());
		}
	}
}

EntityManager::EntityManager() {}

void EntityManager::Update()
{
	// called at beginning of each frame by game engine
	// entities added will now be available to use this frame

	for (auto e : m_toAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->Tag()].push_back(e);
	}

	// for all vecs in entityMap : remove the dead entities
	for (auto& [tag, entityVec] : m_entityMap)
	{
		RemoveDeadEntities(entityVec);
	}

	// reset toAdd array
	m_toAdd.clear();
}

void EntityManager::RenderEntities()
{
	for (auto& e : m_entities)
	{
		if (e->cShape)
		{
			DrawRectangle(e->cShape->m_rectangle.x, e->cShape->m_rectangle.y, e->cShape->m_rectangle.width, e->cShape->m_rectangle.height, WHITE);
		}
	}
}

std::shared_ptr<Entity> EntityManager::AddEntity(const std::string& tag)
{
	// give each entity an increasing integer id
	auto e = std::make_shared<Entity>(tag, m_totalEntities++);
	// add e to the waiting room array toAdd
	m_toAdd.push_back(e);

	return e;
}

EntityVec& EntityManager::GetEntities()
{
	return m_entities;
}

EntityVec& EntityManager::GetEntities(const std::string& tag)
{
	return m_entityMap[tag];
}

const std::map<std::string, EntityVec>& EntityManager::GetEntityMap()
{
	return m_entityMap;
}
