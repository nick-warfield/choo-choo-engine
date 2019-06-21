#ifndef MOVE_HPP_INCLUDED
#define MOVE_HPP_INCLUDED

class Move
{
	public:
		~Move(void) = 0;
		~operator() = 0;

		struct Stats
		{
		};

	private:
		// icon
		// sprite sheet
		std::string m_tooltip;
		std::string m_name;
		static int m_maxUses;
};

#endif
