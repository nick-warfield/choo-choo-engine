#ifndef OUTOFUSES_HPP_INCLUDED
#define OUTOFUSES_HPP_INCLUDED

#include <exception>

class OutOfUses : public std::exception
{
	public:
		const char* what(void) const noexcept;
};

#endif
