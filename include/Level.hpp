#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include <SFML/System.hpp>

#include "Scene.hpp"

class Level : public Scene
{
	public:
		Level(sf::Vector2<int>);	// this should really be reading a file

	private:
		sf::Vector2<int> m_size;
};

#endif
