#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include "Scene.hpp"

class Unit : public Scene
{
	public:
		struct Stats
		{
			Stats(std::vector<int>);
			Stats(int = 1, int = 1, int = 1, int = 1, int = 1, int = 1, int = 1); 
			int Health;
			int Might;
			int Haste;
			int Skill;
			int Brawn;
			int Will;
			int Movement;
		};

	protected:
		void preload(void);

	private:
};

#endif
