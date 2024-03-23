#include "Entity.h"

Entity::Entity(const std::string& tag, size_t id)
	: m_tag(tag)
	, m_id(id)
{
}

const std::string& Entity::Tag() const
{
	return m_tag;
}

const bool& Entity::IsAlive() const
{
	return m_alive;
}
