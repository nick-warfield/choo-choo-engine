#include <algorithm>
#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(
		const std::string& name,
		const std::string& path,
		int frameCount,
		float frameRate) :
	GameObject(name),
	m_currentFrame(0),
	m_frameDuration(1000.0f / frameRate),
	m_frameCount(frameCount),
	m_timer(m_frameDuration, [this]() { nextFrame(); }),
	m_tex(),
	m_palette()
{
	std::vector<sf::Color> pal;
	sf::Image img;
	img.loadFromFile(path);

	// populate palette with unique colors from image
	img = forEachPixel(img,
			[&pal](auto color) {
				if (std::none_of(pal.begin(), pal.end(),
						[color](auto c) { return c == color; }))
				{ pal.push_back(color); }
				return color; });

	// generate palete texture
	std::sort(pal.begin(), pal.end(),
			[](auto a, auto b) { return a.toInteger() < b.toInteger(); });
	sf::Image palImg;
	palImg.create(pal.size(), 1);
	for (uint i = 0; i < pal.size(); ++i) { palImg.setPixel(i, 0, pal[i]); }
	m_palette.loadFromImage(palImg);

	// convert image to greyscale
	uint gap = 256 / pal.size(), mapping = 0;
	for (auto color : pal)
	{
		sf::Color grey(mapping, mapping, mapping, color.a);
		img = forEachPixel(img, [color, grey](auto c) { return color == c ? grey : c; });
		mapping += gap;
		if (mapping >= 256) { mapping = 255; }
	}

	img.saveToFile("resources/" + name + "_greyscale.png");
	palImg.saveToFile("resources/" + name + "_palette.png");

	m_tex.loadFromImage(img);
	setTexture(m_tex);
	setTextureRect(sf::Rect<int>(0, 0, img.getSize().x / m_frameCount, img.getSize().y));

	setPosition(250, 425);
	setScale(10, 10);
}

void AnimatedSprite::play(void) { m_timer.start(); }
void AnimatedSprite::pause(void) { m_timer.pause(); }
void AnimatedSprite::stop(void) { restart(); m_timer.stop(); }
void AnimatedSprite::restart(void) { m_currentFrame = 0; m_timer.restart(); }
bool AnimatedSprite::isPlaying(void) const { return m_timer.isPlaying(); }

void AnimatedSprite::update(const float& delta)
{
	m_timer.update(delta);
}
void AnimatedSprite::draw(
		sf::RenderTarget& target,
		sf::RenderStates states) const
{
	sf::Sprite spr(*getTexture(), getTextureRect());
	spr.setPosition(getPosition());
	spr.setScale(getScale());
	target.draw(spr, states);
}

void AnimatedSprite::setFrame(int frame)
{
	// should bound check and throw error, but lazy right now
	m_currentFrame = frame;
	setTextureRect(sf::Rect<int>(
				m_currentFrame * getTextureRect().width,
				0,
				getTextureRect().width,
				getTextureRect().height));
}
void AnimatedSprite::nextFrame(void)
{
	setFrame(m_currentFrame + 1 >= m_frameCount ? 0 : m_currentFrame + 1);
}

sf::Image AnimatedSprite::forEachPixel(
		const sf::Image& img,
		std::function<sf::Color(sf::Color)> f) const
{
	int width = img.getSize().x;
	int height = img.getSize().y;
	sf::Image output;
	output.create(width, height);

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			output.setPixel(x, y, f(img.getPixel(x, y)));
		}
	}
	return output;
}
