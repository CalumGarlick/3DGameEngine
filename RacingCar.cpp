#include "stdafx.h"
#include "RacingCar.h"
#include "InputHandler.hpp"
#include "CollisionEngine.hpp"

RacingCar::RacingCar(void)
{
}

RacingCar::~RacingCar(void)
{
}

void RacingCar::init()
{
	_gravity = 5;
}

void RacingCar::update()
{
	if(EngineInput::keyboardInput.isKeyHeld(sf::Keyboard::Up))
	{
		std::vector<Actor*>* _actorsReturned = getCollisionEngine().getActorPlaceFree(this,this->_transform._position.x,this->_transform._position.z - 0.1f,this->_transform._position.y);
		if(_actorsReturned != 0)
		{
		}
		else
		{
			_transform.rotate(glm::vec3(0,3,0));
			_transform.setPosition(_transform._position + glm::vec3(0,0,-0.2f));
		}
	}
	if(EngineInput::keyboardInput.isKeyHeld(sf::Keyboard::Right))
	{
		std::vector<Actor*>* _actorsReturned = getCollisionEngine().getActorPlaceFree(this,this->_transform._position.x + 0.1f,this->_transform._position.z,this->_transform._position.y);
		if(_actorsReturned != 0)
		{
		}
		else
		{
			_transform.rotate(glm::vec3(0,1.5f,0));
			_transform.setPosition(_transform._position + glm::vec3(0.2f,0,0.0f));
		}	
	}
	if(EngineInput::keyboardInput.isKeyHeld(sf::Keyboard::Down))
	{
		std::vector<Actor*>* _actorsReturned = getCollisionEngine().getActorPlaceFree(this,this->_transform._position.x,this->_transform._position.z + 0.1f,this->_transform._position.y);
		if(_actorsReturned != 0)
		{
		}
		else
		{
			_transform.rotate(glm::vec3(0,0.0f,0));
			_transform.setPosition(_transform._position + glm::vec3(0,0,0.2f));
		}
	}
	if(EngineInput::keyboardInput.isKeyHeld(sf::Keyboard::Left))
	{
		std::vector<Actor*>* _actorsReturned = getCollisionEngine().getActorPlaceFree(this,this->_transform._position.x - 0.1f,this->_transform._position.z,this->_transform._position.y);
		if(_actorsReturned != 0)
		{
		}
		else
		{
			_transform.rotate(glm::vec3(0,4.5f,0));
			_transform.setPosition(_transform._position + glm::vec3(-0.2f,0,0.0f));
		}
	}
}