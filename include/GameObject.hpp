#ifndef GAME_OBJECT_HPP_INCLUDED
#define GAME_OBJECT_HPP_INCLUDED

#include <iostream>
#include <string>
#include <functional>

#include "Game.hpp"
#include "Listener.hpp"

class GameObject
{
	public:
		GameObject(std::string Name) :
			m_name(Name), m_turnUpdate(std::bind(&GameObject::onTurn, this)) { }

		Listener GetListener(void) { return m_turnUpdate; }

	protected:
		void onTurn(void)
		{
			std::cout << m_name << " started their turn!\n";
		}

	private:
		std::string m_name;
		Listener m_turnUpdate;
};

#endif
