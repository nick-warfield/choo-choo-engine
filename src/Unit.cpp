#include <memory>
#include <exception>

#include "Unit.hpp"
#include "GUI.hpp"

sf::Vector2<int> Unit::getPosition() const { return m_position; }

int Unit::health() const { return m_health.getValue(); }
int Unit::might() const { return m_might.getValue(); }
int Unit::haste() const { return m_haste.getValue(); }
int Unit::skill() const { return m_skill.getValue(); }
int Unit::brawn() const { return m_brawn.getValue(); }
int Unit::will() const { return m_will.getValue(); }
int Unit::movement() const { return m_movement.getValue(); }

Attribute& Unit::getHealth() { return m_health; }
