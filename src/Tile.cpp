#include "Tile.hpp"

Tile::Tile(sf::Vector2<int> position,  std::unique_ptr<Terrain> terrain,
	std::unique_ptr<Unit> unit) : m_position(position),
	m_unit(std::move(unit)), m_terrain(std::move(terrain)) { }

