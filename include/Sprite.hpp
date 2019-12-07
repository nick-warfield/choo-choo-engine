#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include <memory>
#include <vector>
#include <chrono>
#include <string>
#include <functional>
#include <algorithm>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Listener.hpp"

class Sprite : public GameObject
{
	public:
		// take image, convert to greyscale and extract palette
		Sprite(const std::string&, int, float = 15, float = 1);
		// Sprite(..pathToFile..)	// load existing sprite file
		// need copy constructor
		void play(void);
		void pause(void);
		void stop(void);
		void restart(void);
		bool isPlaying(void) const;
		bool inPalette(const sf::Color&) const;
		std::vector<sf::Color> getPalette(void) const;
		void setPalette(std::vector<sf::Color>);
		bool timeout(void) const;
		void setPosition(float, float);

		void update(const float&);
		void draw(sf::RenderTarget&,
				sf::RenderStates = sf::RenderStates::Default) const;

	private:
		bool m_isPlaying;
		const int m_frameDuration, m_frameCount;
		int m_currentFrame;
		float m_timer;
		const float m_scale;

		sf::Image m_spriteSheet;
		sf::Texture m_texture;
		sf::Rect<uint> m_frame;
		std::vector<sf::Color> m_palette;

		sf::Vector2<float> m_position;

		void resetTimer(void);
		void forEachPixel(std::function<void(sf::Color)>) const;
		void forEachPixel(std::function<sf::Color(sf::Color)>);
		void reloadTexture(void);
		sf::Color colorMap(const sf::Color&);
};

#endif
