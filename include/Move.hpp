#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>

#include "Attribute.hpp"
#include "Shape.hpp"

class Move
{
	public:
		Move(std::string, std::string, std::unique_ptr<Shape>); //add textures/icon later
		virtual ~Move(void) = 0;
		virtual void operator()(void) = 0;
		virtual bool isUsable(void);

	protected:
		const std::string m_name;
		const std::string m_tooltip;
		// icon
		// sprite sheet

		Attribute m_uses;
		Attribute m_range;
		const std::unique_ptr<const Shape> m_shape;
};

#endif
