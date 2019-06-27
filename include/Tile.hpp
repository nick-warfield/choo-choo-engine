#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED

#include <memory>

#include <SFML/System.hpp>

#include "Unit.hpp"
#include "Terrain.hpp"

class Unit;

class Tile
{
	public:
		Tile(sf::Vector2<int>, std::unique_ptr<Terrain>,
				std::unique_ptr<Unit> = nullptr);

		bool isOccupied(void) const;
		void transferUnit(Tile&);
		void killUnit(void);
		void setUnit(std::unique_ptr<Unit>);	// tile must be unoccupied
		void setTerrain(std::unique_ptr<Terrain>);
		
	private:
		const sf::Vector2<int> m_position;
		std::unique_ptr<Unit> m_unit;
		std::unique_ptr<Terrain> m_terrain;
};

#endif
