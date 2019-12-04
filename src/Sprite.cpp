#include <iomanip>
#include <algorithm>
#include "Sprite.hpp"

Sprite::Sprite(
		const std::string& Path,
		int FrameCount,
		float FrameRate,
		float Scale) :
	GameObject(Path),
	m_isPlaying(true),
	m_frameDuration(1000.0f / FrameRate),
	m_frameCount(FrameCount),
	m_currentFrame(0),
	m_timer(m_frameDuration),
	m_scale(Scale),
	m_position(1920 / 2, 1080 / 2)
{
	m_spriteSheet = init(Path);
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

sf::Texture Sprite::init(const std::string& Path)
{
	m_palette.clear();
	sf::Image img;
	img.loadFromFile(Path);

	// gen palette
	forEachPixel(img, [this](auto c)
			{ if (!this->inPalette(c)) m_palette.push_back(c); return c; });

	// greyscale mapping
	uint gap = 256 / m_palette.size(), mapping = 0;
	for (auto color : m_palette)
	{
		sf::Color grey(mapping, mapping, mapping, color.a);
		forEachPixel(img, [color, grey](auto c) { return color == c ? grey : c; });
		mapping += gap;
		if (mapping >= 256) { mapping = 255; }
	}

	img.saveToFile("resources/temp.png");
	sf::Texture tex;
	tex.loadFromImage(img);
	return tex;
}

void Sprite::forEachPixel(sf::Image& img, std::function<sf::Color(sf::Color)> f)
{
	int width = img.getSize().x;
	int height = img.getSize().y;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			img.setPixel(x, y, f(img.getPixel(x, y)));
		}
	}
}

bool Sprite::inPalette(const sf::Color& color)
{
	return std::any_of(m_palette.begin(), m_palette.end(),
			[color](auto c) { return c == color; } );
}

void Sprite::resetTimer(void) { m_timer = m_frameDuration; }
