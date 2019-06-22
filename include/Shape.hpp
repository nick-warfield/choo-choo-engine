#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <vector>

#include <SFML/System.hpp>

class Shape
{
	public:
		virtual ~Shape(void);
		const virtual std::vector<sf::Vector2<int>> area(sf::Vector2<int> center,
				sf::Vector2<int> rotation = sf::Vector2<int>()) = 0;
};

#endif
