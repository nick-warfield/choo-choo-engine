#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

#include <string>
#include <vector>

#include "Unit.hpp"
#include "Attribute.hpp"
#include "Shape.hpp"

class Move
{
	public:
		Move(const Unit&);
		virtual ~Move(void) = 0;
		virtual void operator()(void) = 0;
		virtual bool isUsable(void);

	protected:
		std::string m_name;
		std::string m_tooltip;
		// icon
		// sprite sheet

		Attribute m_uses;
		Attribute m_range;
		Shape m_shape;
};

#endif
