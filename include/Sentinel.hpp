#ifndef SENTINEL_HPP_INCLUDED
#define SENTINEL_HPP_INCLUDED

#include "Scene.hpp"

class Sentinel : public Scene
{
	public:
		void preload(void);
		void load(void);
		void unload(void);
};

#endif
