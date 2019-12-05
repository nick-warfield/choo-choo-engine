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
	m_palette(),
	m_position(1920 / 2, 1080 / 2)
{
	m_spriteSheet.loadFromFile(Path);

	// gen palette
	forEachPixel([this](auto color)
			{ if (!inPalette(color)) m_palette.push_back(color); });

	// greyscale mapping
	uint gap = 256 / m_palette.size(), mapping = 0;
	for (auto color : m_palette)
	{
		sf::Color grey(mapping, mapping, mapping, color.a);
		forEachPixel([color, grey](auto c) { return color == c ? grey : c; });
		mapping += gap;
		if (mapping >= 256) { mapping = 255; }
	}

	m_spriteSheet.saveToFile("resources/temp.png");
	m_texture.create(m_spriteSheet.getSize().x, m_spriteSheet.getSize().y);
	reloadTexture();
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
	sf::Sprite spr(m_texture, sf::Rect<int>(m_frame));
	spr.scale(m_scale, m_scale);
	spr.setPosition(m_position);
	target.draw(spr);
}

void Sprite::forEachPixel(std::function<void(sf::Color)> f) const
{
	int width = m_spriteSheet.getSize().x;
	int height = m_spriteSheet.getSize().y;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			f(m_spriteSheet.getPixel(x, y));
		}
	}
}
void Sprite::forEachPixel(std::function<sf::Color(sf::Color)> f)
{
	int width = m_spriteSheet.getSize().x;
	int height = m_spriteSheet.getSize().y;
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			m_spriteSheet.setPixel(x, y, f(m_spriteSheet.getPixel(x, y)));
		}
	}
}

void Sprite::reloadTexture(void)
{
	sf::Image img;
	img.create(m_spriteSheet.getSize().x, m_spriteSheet.getSize().y);
	for (uint x = 0; x < img.getSize().x; ++x)
	{
		for (uint y = 0; y < img.getSize().y; ++y)
		{
			img.setPixel(x, y, colorMap(m_spriteSheet.getPixel(x, y)));
		}
	}
	m_texture.update(img);
}

std::vector<sf::Color> Sprite::getPalette(void) const
{
	return m_palette;
}
void Sprite::setPalette(std::vector<sf::Color> palette)
{
	if (palette.size() != m_palette.size()) { return; }
	m_palette = palette;
	reloadTexture();
}

sf::Color Sprite::colorMap(const sf::Color& grey)
{
	int index = grey.r / (256 / m_palette.size());
	return m_palette[index];
}

bool Sprite::inPalette(const sf::Color& color) const
{
	return std::any_of(m_palette.begin(), m_palette.end(),
			[color](auto c) { return c == color; } );
}

bool Sprite::timeout(void) const { return m_timer <= 0; }
void Sprite::resetTimer(void) { m_timer = m_frameDuration; }
