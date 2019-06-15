#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "SceneTree.hpp"
#include "GUI.hpp"

SceneTree::SceneTree()
{
	m_root = std::make_shared<GUI>();
	std::cout << m_root->id() << std::endl;
}

void SceneTree::addScene(Scene& scene)
{
	m_root->add(std::make_shared<GUI>());
}

void SceneTree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_root == nullptr) { return; }

//	  target.draw(*(m_root->Drawable()), states);

	//draw(*m_root, target, states);
}
void SceneTree::draw(Scene& scene, sf::RenderTarget& target, sf::RenderStates states) const
{
//	  target.draw(*scene.Drawable());
//	  for (auto s : scene.GetChildren())
//	  {
//		  if (s.lock() != nullptr)
//		  {
//			  draw(*s.lock(), target, states);
//		  }
//	  }
}
