#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

int main(void)
{
	Game game;

	while (game.loop());

	game.close();

	return 0;
}
