#include "Point.hpp"

std::vector<sf::Vector2<int>> Point::area(sf::Vector2<int> center,
	sf::Vector2<int> rotation) const
{
	return std::vector<sf::Vector2<int>>(1, center);
}
