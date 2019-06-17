#include <thread>
#include <chrono>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Game.hpp"
#include "Sentinel.hpp"

const int Game::m_frameDuration = 16;

Game::Game()
{
	m_window.create(sf::VideoMode(1, 1), "Float Window");
	auto dt = sf::VideoMode::getDesktopMode();

	m_window.setSize(sf::Vector2u(dt.width * 3 / 5, dt.height * 3 / 5));
	m_window.setPosition(sf::Vector2i(dt.width / 2 - m_window.getSize().x / 2, 
				dt.height / 2 - m_window.getSize().y / 2));
	m_window.setVerticalSyncEnabled(true);
	m_window.setSize(sf::Vector2u(m_window.getSize().x, m_window.getSize().y));
	m_window.setActive(true);

	m_root = std::make_shared<Sentinel>();
	m_root->preload();
	m_root->load();
}

bool Game::loop()
{
	auto nextFrame = std::chrono::system_clock::now() +
		std::chrono::milliseconds(m_frameDuration);

	// get inputs
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) { return false; }
	}

	std::this_thread::sleep_until(nextFrame);
	
	// render
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_window.display();

	return true;
}

void Game::close()
{
	m_root->unload();
	m_window.close();
}
