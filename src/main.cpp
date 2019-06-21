#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Attribute.hpp"

int main(void)
{
	Attribute dex(10);
	std::cout << dex << std::endl;
	dex = 5;
	std::cout << dex << std::endl;
	dex.setMax(12);
	std::cout << dex << std::endl;
	dex.reset();
	std::cout << dex << std::endl;

	return 0;
}
