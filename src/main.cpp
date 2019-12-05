#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "PhalanxDemo.hpp"

int main(void)
{
	Game game;
	game.addObject(std::make_unique<PhalanxDemo>());
	while (game.loop()) { }
	game.close();

	return 0;
}
