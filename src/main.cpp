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
	AnimatedSprite spr1("Phalanx", "resources/Phalanx.png", 2, 1.5);
	spr1.setScale(10, 10);
	spr1.setPosition(250, 425);

	auto spr2 = spr1;
	spr2.setPosition(600, 425);
	sf::Texture red;
	red.loadFromFile("resources/Phalanx_palette_red.png");
	spr2.setPalette(red);

	auto spr3 = spr1;
	spr3.setPosition(950, 425);
	sf::Texture green;
	green.loadFromFile("resources/Phalanx_palette_green.png");
	spr3.setPalette(green);

	AnimatedSprite spr4("Forest", "resources/Forest.png", 1, 1);
	spr4.setScale(10, 10);
	spr4.setPosition(1400, 475);

	game.addObject(std::make_unique<AnimatedSprite>(spr1));
	game.addObject(std::make_unique<AnimatedSprite>(spr2));
	game.addObject(std::make_unique<AnimatedSprite>(spr3));
	game.addObject(std::make_unique<AnimatedSprite>(spr4));

	while (game.loop()) { }
	game.close();

	return 0;
}
