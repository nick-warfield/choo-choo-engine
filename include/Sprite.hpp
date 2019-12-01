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
		Sprite(void);
		// take image, convert to greyscale and extract palette
		Sprite(sf::Image, sf::Vector2<int>, int, int);
		// Sprite(..pathToFile..)	// load existing sprite file
		// need copy constructor
		void Play(void);
		void Pause(void);
		void Stop(void);
		void Restart(void);
		bool isPlaying(void);

	protected:
		virtual void onRender(void);

	private:
		bool m_isPlaying;
		const int m_frameDuration, m_frameCount;
		float m_currentFrame;
		std::chrono::time_point<std::chrono::system_clock> m_timestamp;
		sf::Rect<int> m_frame;
		std::shared_ptr<sf::Texture> m_spriteSheet;
		std::vector<sf::Color> m_palette;
		sf::Vector2<double> m_position;

		void setTimestamp(void);
		void setFrame(void);
};

#endif
