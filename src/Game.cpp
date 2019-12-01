#include <thread>
#include <chrono>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Game.hpp"

const int Game::m_frameDuration = 16;
const int Game::m_width = 1920;
const int Game::m_height = 1080;

Game::Game()
{
	m_window.create(sf::VideoMode(1, 1), "game window");
	auto dt = sf::VideoMode::getDesktopMode();

	m_window.setSize(sf::Vector2u(m_width, m_height));
	m_window.setPosition(sf::Vector2i(dt.width / 2 - m_window.getSize().x / 2, 
				dt.height / 2 - m_window.getSize().y / 2));
	m_window.setVerticalSyncEnabled(true);
	m_window.setSize(sf::Vector2u(m_window.getSize().x, m_window.getSize().y));
	m_window.setActive(true);
}

void Game::addListener(Listener List)
{
	m_frameEvent += List;
}
void Game::addListener(std::vector<Listener> Listeners)
{
	for (auto l = Listeners.begin(); l != Listeners.end(); ++l)
	{
		addListener(*l);
	}
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

	m_frameEvent();
	std::this_thread::sleep_until(nextFrame);
	
	// render
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_window.display();

	return true;
}

void Game::close()
{
	m_window.close();
}
