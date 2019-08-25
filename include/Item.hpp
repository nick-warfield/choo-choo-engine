#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#include <memory>

#include "Move.hpp"
#include "Stats.hpp"

class Item
{
	public:
		enum SLOT { HEAD, CHEST, BOOT, HAND, BELT, NECK, INVENTORY };

		Item(SLOT, Stats = Stats(), std::unique_ptr<Move> = nullptr);
		SLOT slot(void) const;
		Stats stats(void) const;
		std::shared_ptr<const Move> move(void) const;

	private:
		const SLOT m_slot;
		const Stats m_stats;
		const std::shared_ptr<const Move> m_move;
};

#endif
