#include "Sprite.hpp"

Sprite::Sprite()
: GameObject("Sprite"),
	m_isPlaying(true),
	m_frameDuration(1000.0f / 60.0f),
	m_frameCount(1),
	m_currentFrame(0),
	m_scale(1),
	m_frame(0, 0, 16, 16)
	{
		m_spriteSheet.loadFromFile("resources/Phalanx.png");
	}
Sprite::Sprite(
	sf::Image SpriteSheet,
	sf::Vector2<int> SpriteSize,
	int FrameCount,
	int FrameRate,
	float Scale)
: GameObject("Sprite"),
	m_isPlaying(true),
	m_frameDuration(1000.0f / FrameRate),
	m_frameCount(FrameCount),
	m_currentFrame(0),
	m_scale(Scale),
	m_frame(sf::Vector2<int>(0, 0), SpriteSize)
	{
		m_spriteSheet.loadFromFile("resources/Phalanx.png");
	}

bool Sprite::isPlaying(void) const { return m_isPlaying; }
void Sprite::play(void) { m_isPlaying = true; }
void Sprite::pause(void) { m_isPlaying = false; }
void Sprite::stop(void)
{
	m_isPlaying = false;
	restart();
}
void Sprite::restart(void)
{
	m_currentFrame = 0;
	m_frame = sf::Rect<int>(
			0,
			0,
			m_frame.width,
			m_frame.height);
	resetTimer();
}

void Sprite::update(const float& delta)
{
	std::cout << "Sprite update\n";
	if (m_timer > 0 || !isPlaying())
	{
		m_timer -= delta;
		return;
	}
	
	++m_currentFrame;
	if (m_currentFrame >= m_frameCount) { m_currentFrame = 0; }
	m_frame = sf::Rect<int>(
			m_frame.left * m_currentFrame,
			m_frame.top * m_currentFrame,
			m_frame.width,
			m_frame.height);
	resetTimer();
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "Sprite drawn\n";
	target.draw(sf::Sprite(m_spriteSheet));
}

void Sprite::resetTimer(void) { m_timer = m_frameDuration; }
