#include "Sprite.hpp"

Sprite::Sprite(sf::Image SpriteSheet,
	sf::Vector2<int> SpriteSize,
	int FrameCount,
	int FrameRate)
: GameObject("Sprite", std::bind(&Sprite::onRender, this)),
m_frameRate(FrameRate),
m_frameCount(FrameCount),
m_spriteSize(SpriteSize)
{ };

void Sprite::onRender(void) { }
