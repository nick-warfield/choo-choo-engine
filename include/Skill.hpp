#ifndef SKILL_HPP_INCLUDED
#define SKILL_HPP_INCLUDED

#include <string>

namespace Skill
{
	enum NAME
	{
		// use SkillList.def to edit available skills
#define X(a) a,
#include "SkillList.def"
#undef X
		COUNT
	};

	enum RANK { UNTRAINED, D, C, B, A, S };

	void rankUp(RANK);
	std::string toString(NAME);
	std::string toString(RANK);
};

#endif
