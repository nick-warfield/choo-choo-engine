#include "Sprite.hpp"

Sprite::Sprite(
		const std::string& Path,
		int FrameCount,
		float FrameRate,
		float Scale) :
	GameObject("Sprite"),
	m_isPlaying(true),
	m_frameDuration(1000.0f / FrameRate),
	m_frameCount(FrameCount),
	m_currentFrame(0),
	m_timer(m_frameDuration),
	m_scale(Scale),
	m_position(1920 / 2, 1080 / 2)
{
	m_spriteSheet.loadFromFile(Path);
	m_frame = sf::Rect<uint>(sf::Vector2<uint>(0, 0), m_spriteSheet.getSize());
	m_frame.width /= m_frameCount;
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
	m_frame = sf::Rect<uint>(
			0,
			0,
			m_frame.width,
			m_frame.height);
	resetTimer();
}

void Sprite::update(const float& delta)
{
	if (m_timer > 0 || !isPlaying())
	{
		m_timer -= delta;
		return;
	}
	
	++m_currentFrame;
	if (m_currentFrame >= m_frameCount) { m_currentFrame = 0; }
	m_frame = sf::Rect<uint>(
			m_frame.width * m_currentFrame,
			0,
			m_frame.width,
			m_frame.height);
	resetTimer();
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite spr(m_spriteSheet, sf::Rect<int>(m_frame));
	spr.scale(m_scale, m_scale);
	spr.setPosition(m_position);
	target.draw(spr);
}

void Sprite::resetTimer(void) { m_timer = m_frameDuration; }
