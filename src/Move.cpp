#include "Move.hpp"
#include "GameException.hpp"

Move::Move(const Unit& user, std::string name, std::string tooltip,
		std::unique_ptr<Shape> shape, int uses, Attribute range) :
	m_user(user), m_name(name), m_tooltip(tooltip), m_shape(std::move(shape)),
	m_uses(uses), m_range(range) { }

Move::~Move() { }

void Move::use(sf::Vector2<int> target)
{
	if (!isUsable()) { throw GameException::out_of_uses(); }
	if (!inRange(target)) { throw GameException::out_of_range(); }
	
	use_impl(target);
	--m_uses;
}

bool Move::isUsable()
{
	return m_uses.getValue() > m_uses.getFloor();
}

bool inRange(sf::Vector2<int> center)
{
	return true;
}
