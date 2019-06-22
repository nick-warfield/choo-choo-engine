#include "Shape.hpp"

Shape::Shape(const sf::Vector2<int>& center, const sf::Vector2<int>& rotation)
{
	m_center = center;
	m_rotation = rotation;
}

std::vector<sf::Vector2<int>> Shape::area()
{
	return std::vector<sf::Vector2<int>>(1, m_center);
}

void Shape::setCenter(sf::Vector2<int> center)
{
	m_center = center;
}
void Shape::setRotation(sf::Vector2<int> rotation)
{
	m_rotation = rotation;
}
