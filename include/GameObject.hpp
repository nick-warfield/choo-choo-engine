#ifndef GAME_OBJECT_HPP_INCLUDED
#define GAME_OBJECT_HPP_INCLUDED

#include <iostream>
#include <string>
#include <functional>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Listener.hpp"

class GameObject : public sf::Drawable
{
	public:
		GameObject(std::string, const std::function<void()>&);
		GameObject(std::string = "Unnamed",
				const std::vector<std::function<void()>>&
					= std::vector<std::function<void()>>()); 

		std::vector<Listener> GetListeners(void);
		std::string name(void) const;
		virtual void update(const float&);

	protected:
		virtual void onTurn(void);

	private:
		std::string m_name;
		std::vector<Listener> m_listeners;
};

#endif
