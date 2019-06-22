#ifndef SCENE_HPP_INCLUDED
#define SCENE_HPP_INCLUDED

#include <set>
#include <memory>

#include <SFML/Graphics.hpp>

class Scene : private std::enable_shared_from_this<Scene>
{
	public:
		Scene();
		virtual ~Scene(void) = 0;

		void init(void);
		void start(void);
		void update(void);
		void end(void);
	
		unsigned long id(void);

		std::weak_ptr<Scene> get(uint);
		std::weak_ptr<Scene> get(const Scene&);

		void add(std::shared_ptr<Scene>);
		void remove(std::shared_ptr<Scene>);

		std::vector<std::weak_ptr<Scene>> getChildren(void);
		std::weak_ptr<Scene> getParent(void);

	protected:
		virtual void preload(void);
		virtual void postload(void);
		virtual void onStart(void);
		virtual void onUpdate(void);
		virtual void onEnd(void);

	private:
		static unsigned long m_nextId;
		unsigned long m_id;

		std::weak_ptr<Scene> m_parent;
		std::set<std::shared_ptr<Scene>> m_children;

		void setParent(std::weak_ptr<Scene>);
};

#endif
