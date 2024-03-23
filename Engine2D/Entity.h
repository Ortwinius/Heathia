#pragma once
#include <iostream>
#include <vector>
#include "Components.h"

class Entity
{
    const size_t      m_id = 0;
    const std::string m_tag = "Default";
    bool              m_alive = true;
public:
    Entity(const std::string& tag, size_t id);
    const std::string& Tag() const;
    const bool& IsAlive() const;
    // components of Entity
    std::shared_ptr<CTransform>     cTransform;
    std::shared_ptr<CShape>             cShape;
    std::shared_ptr<CBoundingBox> cBoundingBox;
    std::shared_ptr<CInput>             cInput;
};