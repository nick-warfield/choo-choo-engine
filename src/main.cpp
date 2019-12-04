#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Sprite.hpp"

int main(void)
{
	Game game;
	game.addObject(std::make_unique<Sprite>(
				"resources/Phalanx.png",
				2,
				1.5,
				6));
	while (game.loop()) { }
	game.close();

	return 0;
}
