#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

int main(void)
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1, 1), "Float Window");
	auto dt = sf::VideoMode::getDesktopMode();

	window.setSize(sf::Vector2u(dt.width * 3 / 5, dt.height * 3 / 5));
	window.setPosition(sf::Vector2i(dt.width / 2 - window.getSize().x / 2, 
				dt.height / 2 - window.getSize().y / 2));
	window.setVerticalSyncEnabled(true);
	window.setView(sf::View(sf::FloatRect(0, 0,
					window.getSize().x, window.getSize().y)));

	int FrameDuration = 16;
	auto nextFrame = std::chrono::system_clock::now() +
		std::chrono::milliseconds(FrameDuration);
	
	bool exit;
	do
	{
		exit = false;
		// get inputs
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { exit = true; }
		}

		std::this_thread::sleep_until(nextFrame);
		
		// render
		window.clear();
//		window.draw(tree);
		window.display();
	}
	while (!exit);
	window.close();

	return 0;
}
