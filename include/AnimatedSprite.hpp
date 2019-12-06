#ifndef ANIMATEDSPRITE_HPP_INCLUDED
#define ANIMATEDSPRITE_HPP_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Timer.hpp"

class AnimatedSprite : public sf::Sprite, public GameObject
{
	public:
		AnimatedSprite(
			const std::string& name,
			const std::string& path,
			int frameCount,
			float frameRate);

		void play(void);
		void pause(void);
		void stop(void);
		void restart(void);
		bool isPlaying(void) const;

		void update(const float&);
		void draw(sf::RenderTarget&, sf::RenderStates = sf::RenderStates::Default) const;

	private:
		int m_currentFrame;
		const int m_frameDuration, m_frameCount;
		Timer m_timer;
		sf::Texture m_tex, m_palette;

		void setFrame(int);
		void nextFrame(void);
		sf::Image forEachPixel(const sf::Image&, std::function<sf::Color(sf::Color)>) const;
};

#endif
