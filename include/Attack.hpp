#ifndef ATTACK_HPP_INCLUDED
#define ATTACK_HPP_INCLUDED

#include <vector>
#include <memory>

#include "Move.hpp"
#include "Unit.hpp"

class Attack : public Move
{
	public:
		Attack(void);
		void operator()(Unit&, std::vector<Unit>);

	protected:
		Attribute m_damage;
		Attribute m_hit;
		Attribute m_crit;
};

#endif
