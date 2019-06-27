#include "Tile.hpp"
#include "GameException.hpp"

Tile::Tile(sf::Vector2<int> position,  std::unique_ptr<Terrain> terrain,
	std::unique_ptr<Unit> unit) : m_position(position),
	m_unit(std::move(unit)), m_terrain(std::move(terrain)) { }

bool Tile::isOccupied() const { return m_unit == nullptr; }
void Tile::killUnit() { m_unit = nullptr; }
void Tile::setUnit(std::unique_ptr<Unit> unit)
{
	if (isOccupied())
	{ throw GameException::game_exception("Tile is Occupied\n"); }
	if (unit == nullptr)
	{ throw GameException::game_exception("Use killUnit() instead\n"); }

	m_unit = std::move(unit);
}
void Tile::setTerrain(std::unique_ptr<Terrain> terrain)
{
	if (terrain == nullptr)
	{ throw GameException::game_exception("Terrain cannot be null\n"); }
	m_terrain = std::move(terrain);
}
