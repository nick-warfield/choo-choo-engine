#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>

#include <SFML/System.hpp>

#include "Attribute.hpp"
#include "Shape.hpp"

class Unit;

class Move
{
	public:
		virtual ~Move(void) = 0;
		void use(sf::Vector2<int>);
		virtual bool isUsable(void);
		bool inRange(sf::Vector2<int>);

	protected:
		Move(const Unit&, std::string, std::string, std::unique_ptr<Shape>,
				int = 15, Attribute = Attribute(1, 1)); //add textures/icon later

		const Unit& m_user;
		const std::string m_name;
		const std::string m_tooltip;
		// icon
		// sprite sheet

		Attribute m_uses;
		Attribute m_range;
		const std::unique_ptr<const Shape> m_shape;

		virtual void use_impl(sf::Vector2<int>) = 0;
};

#endif
