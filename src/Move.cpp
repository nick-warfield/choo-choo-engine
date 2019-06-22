#include "Move.hpp"

bool Move::isUsable()
{
	return m_uses.getValue() > m_uses.getFloor();
}
