#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include "Scene.hpp"
#include "Attribute.hpp"
#include "Move.hpp"

class Unit : public Scene
{
	public:
		struct Stats
		{
			Stats(std::vector<int>);
			Stats(int = 1, int = 1, int = 1, int = 1, int = 1, int = 1, int = 1); 
			Attribute Health;
			Attribute Might;
			Attribute Haste;
			Attribute Skill;
			Attribute Brawn;
			Attribute Will;
			Attribute Movement;
		};

	protected:
		void preload(void);

	private:
};

#endif
