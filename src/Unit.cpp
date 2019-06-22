#include <memory>
#include <exception>

#include "Unit.hpp"
#include "GUI.hpp"

void Unit::preload()
{
	auto g = std::make_shared<GUI>();
	for (int i = 0; i < 5; ++i)
	{
		g->add(std::make_shared<GUI>());
	}
	add(g);
}

Unit::Stats::Stats(std::vector<int> stats)
{
	if (stats.size() != 7)
	{
		throw std::invalid_argument("Vector must be size 7");
	}
	Health = Attribute(stats[0]);
	Might = Attribute(stats[1]);
	Haste = Attribute(stats[2]);
	Skill = Attribute(stats[3]);
	Brawn = Attribute(stats[4]);
	Will = Attribute(stats[5]);
	Movement = Attribute(stats[6]);
}

Unit::Stats::Stats(int health, int might, int haste,
		int skill, int brawn, int will, int movement) :
	Health(health), Might(might), Haste(haste), Skill(skill),
	Brawn(brawn), Will(will), Movement(movement) { }

