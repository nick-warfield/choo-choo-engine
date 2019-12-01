#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Sprite.hpp"

int main(void)
{
	Game game;
	Sprite sprite;
	game.addListener(sprite.GetListeners());
	sprite.Play();
	while (game.loop()) { }
	game.close();

	return 0;
}
