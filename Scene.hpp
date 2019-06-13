#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <vector>
#include <memory>

class Scene : public std::enable_shared_from_this<Scene>
{
    public:
		Scene();
        virtual ~Scene(void) = 0;

        // always called before load
        virtual void preload(void) = 0;

        // when the scene enters tree, called once and only once
        virtual void load(void) = 0;
        
        // when the scene exits, called once and only once
        virtual void unload(void) = 0;

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
		std::weak_ptr<Scene> m_parent;
        std::vector<std::shared_ptr<Scene>> m_children;

		void setParent(std::weak_ptr<Scene>);
};

#endif
