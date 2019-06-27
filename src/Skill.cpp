#include "Skill.hpp"
#include "GameException.hpp"

void Skill::rankUp(RANK rank)
{
	switch (rank)
	{
		case RANK::UNTRAINED: rank = RANK::D; break;
		case RANK::D: rank = RANK::C; break;
		case RANK::C: rank = RANK::B; break;
		case RANK::B: rank = RANK::A; break;
		case RANK::A: rank = RANK::S; break;
	}
}

std::string Skill::toString(RANK rank)
{
	switch (rank)
	{
		case RANK::UNTRAINED: return "Untrained";
		case RANK::D: return "D";
		case RANK::C: return "C";
		case RANK::B: return "B";
		case RANK::A: return "A";
		case RANK::S: return "S";
		default: throw GameException::game_exception("Skill Rank Not Found");
	}
}

std::string Skill::toString(NAME name)
{
	std::string s;
	switch (name)
	{
#define X(a) case a: s = #a; break;
#include "SkillList.def"
#undef X
		default: throw GameException::game_exception("Skill Name not found");
	}

	for (int i = 1; i < s.size(); ++i) { s[i] = s[i] - ('A' - 'a'); }
	return s;
}
