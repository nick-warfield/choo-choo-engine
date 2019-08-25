#include "Item.hpp"
#include "Shape.hpp"

Item::Item(SLOT slot, Stats stats, std::unique_ptr<Move> move) :
	m_slot(slot), m_stats(stats), m_move(std::move(move)) { }

Item::SLOT Item::slot(void) const { return m_slot; }
Stats Item::stats(void) const { return m_stats; }
std::shared_ptr<const Move> Item::move(void) const { return m_move; }
