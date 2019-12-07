#include <algorithm>
#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite(const AnimatedSprite& other) :
	GameObject(other.name()),
	m_currentFrame(other.m_currentFrame),
	m_frameDuration(other.m_frameDuration),
	m_frameCount(other.m_frameCount),
	m_frame(other.m_frame),
	m_timer(m_frameDuration, [this]() { nextFrame(); }),
	m_tex(other.m_tex),
	m_palette(other.m_palette),
	m_colorLookup(other.m_colorLookup) { }

AnimatedSprite::AnimatedSprite(
		const std::string& name,
		const std::string& path,
		int frameCount,
		float frameRate) :
	GameObject(name),
	m_currentFrame(0),
	m_frameDuration(1000.0f / frameRate),
	m_frameCount(frameCount),
	m_frame(),
	m_timer(m_frameDuration, [this]() { nextFrame(); }),
	m_tex(std::make_shared<sf::Texture>()),
	m_palette(std::make_shared<sf::Texture>()),
	m_colorLookup(std::make_shared<sf::Shader>())
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
	m_palette->loadFromImage(palImg);

	// convert image to greyscale
	float gap = 256.0f / (pal.size() - 1), mapping = 0;
	for (auto color : pal)
	{
		sf::Color grey(mapping, mapping, mapping, color.a);
		img = forEachPixel(img, [color, grey](auto c) { return color == c ? grey : c; });
		mapping += gap;
		if (mapping >= 256) { mapping = 255; }
	}

	img.saveToFile("resources/" + name + "_greyscale.png");
	palImg.saveToFile("resources/" + name + "_palette.png");

	m_tex->loadFromImage(img);
	m_frame.setTexture(*m_tex);
	m_frame.setTextureRect(sf::Rect<int>(0, 0, img.getSize().x / m_frameCount, img.getSize().y));

	m_colorLookup->loadFromFile("resources/color_lookup.fragment", sf::Shader::Fragment);
	m_colorLookup->setUniform("tex", *m_tex);
	m_colorLookup->setUniform("palette", *m_palette);

	m_frame.setPosition(250, 425);
	m_frame.setScale(10, 10);
}

void AnimatedSprite::play(void) { m_timer.start(); }
void AnimatedSprite::pause(void) { m_timer.pause(); }
void AnimatedSprite::stop(void) { restart(); m_timer.stop(); }
void AnimatedSprite::restart(void) { setFrame(0); m_timer.restart(); }
bool AnimatedSprite::isPlaying(void) const { return m_timer.isPlaying(); }

void AnimatedSprite::update(const float& delta)
{
	m_timer.update(delta);
}
void AnimatedSprite::draw(
		sf::RenderTarget& target,
		sf::RenderStates states) const
{
	states.shader = m_colorLookup.get();
	target.draw(m_frame, states);
}

void AnimatedSprite::setPosition(float x, float y) { m_frame.setPosition(x, y); }
void AnimatedSprite::setPosition(const sf::Vector2f& coords) { m_frame.setPosition(coords); }
void AnimatedSprite::setRotation(float rotation) { m_frame.setRotation(rotation); }
void AnimatedSprite::setScale(float x, float y) { m_frame.setScale(x, y); }

const sf::Vector2f& AnimatedSprite::getPosition(void) const { return m_frame.getPosition(); }
float AnimatedSprite::getRotation(void) const { return m_frame.getRotation(); }
const sf::Vector2f& AnimatedSprite::getScale(void) const { return m_frame.getScale(); }

void AnimatedSprite::setPalette(std::shared_ptr<sf::Texture> palette)
{
	m_palette = palette;
	m_colorLookup->setUniform("palette", *m_palette);
}

void AnimatedSprite::setFrame(int frame)
{
	// should bound check and throw error, but lazy right now
	m_currentFrame = frame;
	auto rect = m_frame.getTextureRect();

	m_frame.setTextureRect(sf::Rect<int>(
				m_currentFrame * rect.width,
				0,
				rect.width,
				rect.height));
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
