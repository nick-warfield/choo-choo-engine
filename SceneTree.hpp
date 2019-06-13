#ifndef SCENETREE_H_INCLUDED
#define SCENETREE_H_INCLUDED

#include <memory>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class SceneTree : public sf::Drawable
{
    public:
        void AddScene(Scene&);
        void RemoveScene(Scene&);

        void UpdateScenes(void);

    protected:
        void draw(sf::RenderTarget&, sf::RenderStates) const;

    private:
        void draw(Scene&, sf::RenderTarget&, sf::RenderStates) const;
        std::unique_ptr<Scene> m_root;
};

#endif
