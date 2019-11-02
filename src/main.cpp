#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Event.hpp"
#include "Listener.hpp"
#include "GameObject.hpp"

int main(void)
{
	Game game;
	GameObject go("stuff");
	game.addListener(go.GetListener());
	while (game.loop()) { }
	game.close();

	return 0;
}
