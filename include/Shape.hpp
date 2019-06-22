#ifndef SHAPE_HPP_INCLUDED
#define SHAPE_HPP_INCLUDED

#include <vector>

#include <SFML/System.hpp>

class Shape
{
	public:
		Shape(const sf::Vector2<int>&,
				const sf::Vector2<int>& = sf::Vector2<int>());
		virtual ~Shape(void);
		virtual std::vector<sf::Vector2<int>> area(void);
		
		void setCenter(sf::Vector2<int>);
		void setRotation(sf::Vector2<int>);

	private:
		sf::Vector2<int> m_center, m_rotation;
};

#endif
