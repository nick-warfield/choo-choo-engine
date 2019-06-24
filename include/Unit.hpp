#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include "Scene.hpp"
#include "Attribute.hpp"
#include "Move.hpp"

class Unit : public Scene
{
	public:
		sf::Vector2<int> getPosition(void) const;

		int health(void) const;
		int might(void) const;
		int haste(void) const;
		int skill(void) const;
		int brawn(void) const;
		int will(void) const;
		int movement(void) const;

		Attribute& getHealth(void);

	private:
		sf::Vector2<int> m_position;

		Attribute m_health;
		Attribute m_might;
		Attribute m_haste;
		Attribute m_skill;
		Attribute m_brawn;
		Attribute m_will;
		Attribute m_movement;
};

#endif
