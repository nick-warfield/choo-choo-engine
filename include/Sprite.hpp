#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include <memory>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Listener.hpp"

class Sprite : public GameObject
{
	public:
		// take image, convert to greyscale and extract palette
		Sprite(sf::Image, sf::Vector2<int>, int, int);
		// Sprite(..pathToFile..)	// load existing sprite file
		// need copy constructor

	protected:
		virtual void onRender(void);

	private:
		int m_frameRate, m_frameCount;
		sf::Vector2<int> m_spriteSize;
		std::shared_ptr<sf::Texture> m_spriteSheet;
		std::vector<sf::Color> m_palette;
		sf::Vector2<double> m_position;
};

#endif
