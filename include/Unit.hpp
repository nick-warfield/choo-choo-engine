#ifndef UNIT_HPP_INCLUDED
#define UNIT_HPP_INCLUDED

#include <unordered_map>

#include "Scene.hpp"
#include "Attribute.hpp"
#include "Move.hpp"
#include "Skill.hpp"

class Unit : public Scene
{
	public:
		int hp(void) const;
		int movement(void) const;
		int speed(void) const;

		int hit(void) const;
		int crit(void) const;
		int atkPower(void) const;
		int magPower(void) const;

		int dodge(void) const;		// single target attack evasion
		int resist(void) const;		// aoe and debuff evasion
		int atkDefense(void) const;
		int magDefense(void) const;

		sf::Vector2<int> getPosition(void) const;

		Skill::RANK getSkill(Skill::NAME) const;
		void levelSkill(Skill::NAME);
		void trainSkill(Skill::NAME);


	private:
		sf::Vector2<int> m_position;

		Attribute m_hp;
		Attribute m_movement;

		std::unordered_map<Skill::NAME, Skill::RANK> m_skills;

		// inventory:
		// -armour determines hp + defenses, cannot be changed during combat
		// -weapons give moves
		// -wearables give stat boosts (eg: +1 damage), effects
		// -not strict, crossover is allowed, just 3 general types

		// skills/proficiencies:
		// -gatekeep access to gear (eg: B rank sword requires B sword skill)
		// -can be leveled up, never down (untrained, D, C, B, A, S)
		// -training a new skill should be difficult or come with risk
		// -getting an S rank should be difficult
		// -skills rank up with skill points or trainers; skill points are 
		//   awarded for completing main quests. trainers need to be found, 
		//   require gold, and only train 1 skill
		// -skills could also make you better at using moves
		
		// quirks:
		// -customize the character in some way
		// -basically an item that is always equipped
		
		// buffs/debuffs:
		// -container to hold temporary changes to stats
};

#endif
