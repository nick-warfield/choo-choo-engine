#ifndef ATTACK_HPP_INCLUDED
#define ATTACK_HPP_INCLUDED

#include "Move.hpp"

class Attack : public Move
{
	protected:
		Attribute m_damage;
		Attribute m_hit;
		Attribute m_crit;
};

#endif
