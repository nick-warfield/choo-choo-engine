#include "GameException.hpp"

GameException::game_exception::game_exception(const char* const message) :
	std::runtime_error(message + '\n') { }

GameException::out_of_uses::out_of_uses() :	game_exception("Out of Uses") { }

GameException::out_of_range::out_of_range() : game_exception("Out of Range") { }
