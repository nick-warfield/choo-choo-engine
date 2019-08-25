#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Skill.hpp>

int main(void)
{
	Skill::RANK r = Skill::RANK::UNTRAINED;
	Skill::rankUp(r);
	std::cout << Skill::toString(r) << std::endl;

	return 0;
}
