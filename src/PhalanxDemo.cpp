#include "PhalanxDemo.hpp"

PhalanxDemo::PhalanxDemo(void) :
	Sprite("resources/Phalanx.png", 2, 1.5, 6) { }

void PhalanxDemo::update(const float& delta)
{
	if (timeout() && isPlaying())
	{
		auto p = getPalette();
		auto c = p.begin();
		++c;
		for (; c != p.end(); ++c)
		{
			uint r = std::rand() % 256;
			uint g = std::rand() % 256;
			uint b = std::rand() % 256;
			*c = sf::Color(r, g, b);
		}
		setPalette(p);
	}

	Sprite::update(delta);
}
