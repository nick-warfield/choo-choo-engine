#include "Sprite.hpp"

Sprite::Sprite(void)
: GameObject("Sprite", std::bind(&Sprite::onRender, this)),
	m_isPlaying(false),
	m_frameDuration(1000.0f / 60.0f),
	m_frameCount(1),
	m_currentFrame(0),
	m_frame(0, 0, 16, 16)
	{ }
Sprite::Sprite(sf::Image SpriteSheet,
	sf::Vector2<int> SpriteSize,
	int FrameCount,
	int FrameRate)
: GameObject("Sprite", std::bind(&Sprite::onRender, this)),
	m_frameDuration(1000.0f / FrameRate),
	m_frameCount(FrameCount),
	m_currentFrame(0),
	m_frame(sf::Vector2<int>(0, 0), SpriteSize)
	{ }

void Sprite::Play(void)
{
	m_isPlaying = true;
	setFrame();
	setTimestamp();
}
void Sprite::Pause(void) { m_isPlaying = false; }
void Sprite::Stop(void)
{
	m_isPlaying = false;
	Restart();
}
void Sprite::Restart(void)
{
	m_currentFrame = 0;
	setFrame();
	setTimestamp();
}
bool Sprite::isPlaying(void) { return m_isPlaying; }

void Sprite::onRender(void)
{
	if (std::chrono::system_clock::now() < m_timestamp || !isPlaying())
	{ return; }

	++m_currentFrame;
	if (m_currentFrame >= m_frameCount) { m_currentFrame = 0; }
	setFrame();

	std::cout << GetName() << " - Frame: " << m_currentFrame << "\n";
	setTimestamp();
}

void Sprite::setTimestamp(void)
{
	m_timestamp = std::chrono::system_clock::now() +
		std::chrono::milliseconds(m_frameDuration);
}

void Sprite::setFrame(void)
{
	m_frame = sf::Rect<int>(
			m_frame.left * m_currentFrame,
			m_frame.top * m_currentFrame,
			m_frame.width,
			m_frame.height);
}
