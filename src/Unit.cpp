#include "Unit.hpp"

sf::Vector2<int> Unit::getPosition() const { return m_position; }

Skill::RANK Unit::getSkill(Skill::NAME name) const
{
	auto r = m_skills.find(name);
	return r == m_skills.end() ? Skill::RANK::UNTRAINED : r->second;
}

void Unit::levelSkill(Skill::NAME skill)
{
	auto r = m_skills.find(skill);
	if (r != m_skills.end()) { Skill::rankUp(r->second); }
}

void Unit::trainSkill(Skill::NAME skill)
{
	if (m_skills.find(skill) == m_skills.end())
	{ m_skills.emplace(skill, Skill::D); }
}
