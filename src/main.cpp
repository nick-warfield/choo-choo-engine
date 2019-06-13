#include <iostream>
#include "Scene.hpp"

class Test : public Scene
{
	public:
		~Test() { }
		void preload() { }
		void load() { }
		void unload() { }
};

int main(void)
{
	std::shared_ptr<Test> t = std::make_shared<Test>();
	std::cout << t->id() << std::endl;


	for (int i = 0; i < 50; ++i)
	{
		std::shared_ptr<Test> child = std::make_shared<Test>();
		t->add(child);
	}

	for (auto child : t->getChildren())
	{
		std::cout << child.lock()->id() << " ";
	}
	std::cout << std::endl;

	return 0;
}
