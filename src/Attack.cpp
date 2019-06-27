#include "Attack.hpp"
#include "Point.hpp"

Attack::Attack(const Unit& user) : Move(user, "Attack", "This is an Attack!",
		std::make_unique<Point>()),	m_damage(3), m_hit(80), m_crit(5) { }

Attack::~Attack() { }

bool Attack::isUsable() { return false; }

void Attack::use_impl(std::vector<std::reference_wrapper<Unit>> targets)
{
	for (auto t : targets)
	{

	}
}

