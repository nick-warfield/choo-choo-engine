#ifndef GAMEEXCEPTION_HPP_INCLUDED
#define GAMEEXCEPTION_HPP_INCLUDED

#include <stdexcept>

namespace GameException
{
	class game_exception : public std::runtime_error
	{
		public:
			game_exception(const char* const message);
	};

	class out_of_uses : public game_exception
	{
		public:
			out_of_uses(void);
	};

	class out_of_range : public game_exception
	{
		public:
			out_of_range(void);
	};
}

#endif
