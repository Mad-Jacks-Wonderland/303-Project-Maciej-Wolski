#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "NetworkServerManager.h"


enum Type { PLAYER, OBJECT };

struct objectStruct {             // Structure declaration
	int id;
	Type objectType;
	sf::CircleShape circle;         // Member (int variable)
	sf::Vector2f velocity;   // Member (string variable)
};        // Structure variable

struct messageTemplate {

	int id;
	Type objectType;
	float x, y;

};

class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt)override;
	void render()override;
	float distance(sf::Vector2f, sf::Vector2f);
	void disconnect();

	std::vector<objectStruct> structVec;

	objectStruct playerObjectStruct;

private:
	// Default functions for rendering to the screen.
	

	// Default variables for level class.
	//sf::CircleShape circle;
	//sf::CircleShape pCircle;
	//sf::Vector2f velocity;
	//sf::Vector2f pVelocity;
	

	NetworkServerManager server;
};