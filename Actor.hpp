#ifndef ACTOR_HPP
#define ACTOR_HPP

//GLM
#include <glm.hpp>

//3DGameEngine
#include "DrawingInstance.hpp"
#include "Transform.hpp"
#include "Collider.hpp"

class CollisionEngine;

/*! The base object that all game objects derive from */
class Actor
{
private:
	bool _gridLocked;
	sf::Vector2i _gridPos;
	
	
public:
	Transform		_transform;			//!< The transform of the gameobject, defines position rotatation scale etc
	DrawingInstance drawingInstance;	//!< Handles the drawing of the game object, represents the game object visually
	CollisionEngine& getCollisionEngine();
	CollisionEngine* _collisionEngine;
	Collider _collision;

	bool isGridLocked();
	void setGridLocked(bool s)
	{
		_gridLocked = s;
	}
	sf::Vector2i getGridPos();
	void setGridPos(sf::Vector2i g)
	{
		_gridPos = g;
	}
	virtual void init();				//!< Called by the scene to initialize the object when it is created, override this to define the behaviour
	virtual void update();				//!< Called by the scene override this to define the behaviour of the object for updating
};
#endif // !GAMEOBJECT_H
