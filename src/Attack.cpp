#include "Attack.hpp"
#include "Point.hpp"

Attack::Attack() : Move("Attack", "This is an Attack!", std::make_unique<Point>()),
	m_damage(3), m_hit(80), m_crit(5) { }

void Attack::operator()(Unit& user, std::vector<Unit> targets)
{

}
