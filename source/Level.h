#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "components/collision/Collision.h"
#include "components/game object/GameObject.h"
#include <list>

class Level
{
private:
	//std::list<Collision*>* Collision;
	//std::list<GameObject*>* GameObjects;
public:
	Level();

	void initialize();
	
	~Level();
};
#endif