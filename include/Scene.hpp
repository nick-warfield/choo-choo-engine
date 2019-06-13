#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <vector>
#include <memory>

class Scene : public std::enable_shared_from_this<Scene>
{
	public:
		Scene();
		virtual ~Scene(void) = 0;

		virtual void preload(void) { }
		virtual void load(void) { }
		virtual void unload(void) { }
	
		virtual void draw(void) { }

		uint id(void);
		std::weak_ptr<Scene> get(uint);
		std::weak_ptr<Scene> get(const Scene&);

		void add(std::shared_ptr<Scene>);
		void remove(Scene&);

		std::vector<std::weak_ptr<Scene>> getChildren(void);
		std::weak_ptr<Scene> getParent(void);

	private:
		static uint m_nextId;
		uint m_id;

		bool m_isVisible;

		std::weak_ptr<Scene> m_parent;
		std::vector<std::shared_ptr<Scene>> m_children;

		void setParent(std::weak_ptr<Scene>);
};

#endif
