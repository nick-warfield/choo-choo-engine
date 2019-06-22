#include "Move.hpp"

Move::Move(std::string name, std::string tooltip, std::unique_ptr<Shape> shape) :
	m_name(name), m_tooltip(tooltip), m_shape(std::move(shape)) { }

Move::~Move() { }

bool Move::isUsable()
{
	return m_uses.getValue() > m_uses.getFloor();
}
