#ifndef ATTACK_HPP_INCLUDED
#define ATTACK_HPP_INCLUDED

#include <vector>
#include <memory>

#include "Move.hpp"
#include "Unit.hpp"

class Attack : public Move
{
	public:
		Attack(const Unit& user);
		~Attack(void);
		bool isUsable(void);

	protected:
		Attribute m_damage;
		Attribute m_hit;
		Attribute m_crit;

		void use_impl(std::vector<std::reference_wrapper<Unit>>);
};

#endif
