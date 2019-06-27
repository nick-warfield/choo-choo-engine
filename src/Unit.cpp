#include "Unit.hpp"

sf::Vector2<int> Unit::getPosition() const { return m_position; }

int Unit::hp() const { return m_hp.getValue(); }
int Unit::movement() const { return m_movement.getValue(); }
int Unit::speed() const { return 0; }

int Unit::hit() const { return 0; }
int Unit::crit() const { return 0; }
int Unit::atkPower() const { return 0; }
int Unit::magPower() const { return 0; }

int Unit::dodge() const { return 0; }
int Unit::resist() const { return 0; }
int Unit::atkDefense() const { return 0; }
int Unit::magDefense() const { return 0; }

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
