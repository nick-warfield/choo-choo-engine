#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "AnimatedSprite.hpp"
#include "PhalanxDemo.hpp"
#include "TerrainDemo.hpp"

int main(void)
{
	Game game;
	game.addObject(std::make_unique<AnimatedSprite>(
				"Phalanx",
				"resources/Phalanx.png",
				2,
				1.5));
	game.addObject(std::make_unique<PhalanxDemo>());
	game.addObject(std::make_unique<TerrainDemo>());
	while (game.loop()) { }
	game.close();

	return 0;
}
