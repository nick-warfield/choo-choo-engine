#include <thread>
#include <chrono>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Game.hpp"

const int Game::m_frameDuration = 16;
const int Game::m_width = 1920;
const int Game::m_height = 1080;

Game::Game() : m_objects(), m_oldTime(std::chrono::system_clock::now())
{
	m_window.create(sf::VideoMode(m_width, m_height), "game window");
	auto dt = sf::VideoMode::getDesktopMode();

	m_window.setPosition(sf::Vector2i(dt.width / 2 - m_window.getSize().x / 2, 
				dt.height / 2 - m_window.getSize().y / 2));
	m_window.setVerticalSyncEnabled(true);
	m_window.setActive(true);
}

void Game::addListener(Listener List)
{
	m_frameEvent += List;
}
void Game::addListener(std::vector<Listener> Listeners)
{
	for (auto l : Listeners) { addListener(l); }
}
void Game::addObject(std::unique_ptr<GameObject> obj)
{
	m_objects.push_back(std::move(obj));
}

bool Game::loop()
{
	auto now = std::chrono::system_clock::now();
	auto nextFrame = now + std::chrono::milliseconds(m_frameDuration);
	auto delta = std::chrono::duration<float>(now - m_oldTime);
	m_oldTime = now;

	// get inputs
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) { return false; }
	}
	for (auto& obj : m_objects) { obj->update(delta.count()); }
	
	// render
	m_window.clear();
	for (auto& obj : m_objects) { m_window.draw(*obj); }
	m_window.display();

	std::this_thread::sleep_until(nextFrame);

	return true;
}

void Game::close()
{
	m_window.close();
}
