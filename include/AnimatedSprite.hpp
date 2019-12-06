#ifndef ANIMATEDSPRITE_HPP_INCLUDED
#define ANIMATEDSPRITE_HPP_INCLUDED

#include <vector>
#include <algorithm>
#include <memory>

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Timer.hpp"

class AnimatedSprite : public GameObject
{
	public:
		AnimatedSprite(const AnimatedSprite&);
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

		// maybe inherit from sf::Transformable for these?
		void setPosition(float, float);
		void setPosition(const sf::Vector2f&);
		void setRotation(float);
		void setScale(float, float);

		const sf::Vector2f& getPosition(void) const;
		float getRotation(void) const;
		const sf::Vector2f& getScale(void) const;

	private:
		int m_currentFrame;
		const int m_frameDuration, m_frameCount;
		sf::Sprite m_frame;
		Timer m_timer;
		std::shared_ptr<sf::Texture> m_tex, m_palette;
		std::shared_ptr<sf::Shader> m_colorLookup;

		void setFrame(int);
		void nextFrame(void);
		sf::Image forEachPixel(const sf::Image&, std::function<sf::Color(sf::Color)>) const;
};

#endif
