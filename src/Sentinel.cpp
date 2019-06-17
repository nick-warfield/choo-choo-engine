#include <iostream>
#include "Sentinel.hpp"

void Sentinel::preload()
{
	std::cout << "Sentinel with id: " << id() << " created!\n";
}

void Sentinel::load()
{
	std::cout << "Sentinel with id: " << id() << " loaded!\n";
}

void Sentinel::unload()
{
	std::cout << "Sentinel with id: " << id() << " destroyed!\n";
}
