#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Skill.hpp>

int main(void)
{
	Skill::NAME s = Skill::NAME::AXE;
	std::cout << Skill::toString(s) << std::endl;

	return 0;
}
