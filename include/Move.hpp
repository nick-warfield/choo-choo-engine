#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>

#include "Attribute.hpp"
#include "Shape.hpp"

class Unit;

class Move
{
	public:
		virtual ~Move(void) = 0;
		virtual void operator()(Unit&, std::vector<Unit>) = 0;
		virtual bool isUsable(void);

	protected:
		Move(std::string, std::string, std::unique_ptr<Shape>); //add textures/icon later

		const std::string m_name;
		const std::string m_tooltip;
		// icon
		// sprite sheet

		Attribute m_uses;
		Attribute m_range;
		const std::unique_ptr<const Shape> m_shape;
};

#endif
