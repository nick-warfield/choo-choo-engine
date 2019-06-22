#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include "Shape.hpp"

class Point : public Shape
{
	public:
		const std::vector<sf::Vector2<int>> area(sf::Vector2<int>,
				sf::Vector2<int> = sf::Vector2<int>());
};

#endif
