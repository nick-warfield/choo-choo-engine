#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include <memory>
#include <vector>
#include <chrono>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Listener.hpp"

class Sprite : public GameObject
{
	public:
		Sprite();
		// take image, convert to greyscale and extract palette
		Sprite(sf::Vector2<int>, int, int, float = 1);
		// Sprite(..pathToFile..)	// load existing sprite file
		// need copy constructor
		void play(void);
		void pause(void);
		void stop(void);
		void restart(void);
		bool isPlaying(void) const;

		void update(const float&);
		void draw(sf::RenderTarget&,
				sf::RenderStates = sf::RenderStates::Default) const;

	private:
		bool m_isPlaying;
		const int m_frameDuration, m_frameCount;
		int m_currentFrame;
		float m_timer;
		const float m_scale;
		sf::Rect<int> m_frame;
		sf::Texture m_spriteSheet;
		std::vector<sf::Color> m_palette;
		sf::Vector2<double> m_position;

		void resetTimer(void);
};

#endif
