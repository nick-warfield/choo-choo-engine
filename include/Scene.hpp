#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

class Scene : private std::enable_shared_from_this<Scene>
{
	public:
		Scene();
		virtual ~Scene(void) = 0;

		virtual void preload(void) { }
		virtual void load(void) { }
		virtual void unload(void) { }
	
		virtual void draw(void) { }

		unsigned long id(void);
		bool isVisible(void);
		void setVisible(bool);

		sf::Texture getTexture(void);
		void setTexture(sf::Texture);

		sf::Transform getTransform(void);
		void setTransform(sf::Transform);

		std::weak_ptr<Scene> get(uint);
		std::weak_ptr<Scene> get(const Scene&);

		void add(std::shared_ptr<Scene>);
		void remove(Scene&);

		std::vector<std::weak_ptr<Scene>> getChildren(void);
		std::weak_ptr<Scene> getParent(void);

	private:
		static unsigned long m_nextId;
		unsigned long m_id;
		bool m_isVisible;
		sf::Texture m_texture;
		sf::Transform m_transform;

		std::weak_ptr<Scene> m_parent;
		std::vector<std::shared_ptr<Scene>> m_children;

		void setParent(std::weak_ptr<Scene>);
};

#endif
