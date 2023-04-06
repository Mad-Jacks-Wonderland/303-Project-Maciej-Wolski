#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	sf::Vector2u bounds = window->getSize();;

	//sf::Vector2i pos = static_cast<sf::Vector2i>(circle.getPosition());

	// initialise game objects

	

	playerObjectStruct.circle.setRadius(20);
	playerObjectStruct.circle.setPosition((100), (100));
	playerObjectStruct.circle.setFillColor(sf::Color::Green);
	playerObjectStruct.circle.setOutlineColor(sf::Color::Cyan);
	playerObjectStruct.circle.setOutlineThickness(2.0f);

	playerObjectStruct.velocity.x = 0.0f;
	playerObjectStruct.velocity.y = 0.0f;

	playerObjectStruct.objectType = PLAYER;

	//structVec.push_back(playerObjectStruct);

	for (int i = 0; i < 4; i++) {

		int pos = 50;
		objectStruct newObjectStruct;
		newObjectStruct.circle.setRadius(20);
		newObjectStruct.circle.setPosition((pos * i), (75 * i));
		newObjectStruct.circle.setFillColor(sf::Color::Blue);
		newObjectStruct.circle.setOutlineColor(sf::Color::Red);
		newObjectStruct.circle.setOutlineThickness(2.0f);

		newObjectStruct.velocity.x = 0.0f;
		newObjectStruct.velocity.y = 0.0f;

		newObjectStruct.objectType = OBJECT;

		structVec.push_back(newObjectStruct);
	}


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::D) && input->isKeyDown(sf::Keyboard::D))
	{
		playerObjectStruct.velocity.x = playerObjectStruct.velocity.x + 9;
		//pVelocity.x = pVelocity.x + 9;
	}

	if (input->isPressed(sf::Keyboard::A) && input->isKeyDown(sf::Keyboard::A))
	{
		playerObjectStruct.velocity.x = playerObjectStruct.velocity.x - 9;
		//pVelocity.x = pVelocity.x - 9;
	}

	if (input->isPressed(sf::Keyboard::S) && input->isKeyDown(sf::Keyboard::S))
	{

		playerObjectStruct.velocity.y = playerObjectStruct.velocity.y + 9;
		//pVelocity.y = pVelocity.y + 9;
	}

	if (input->isPressed(sf::Keyboard::W) && input->isKeyDown(sf::Keyboard::W))
	{
		playerObjectStruct.velocity.y = playerObjectStruct.velocity.y - 9;
		//pVelocity.y = pVelocity.y - 9;
	}
}

// Update game objects
void Level::update(float dt)
{

	sf::Vector2u bounds = window->getSize();



	for (int i = 0; i < structVec.size(); i++)
	{


		float dis = distance(playerObjectStruct.circle.getPosition(), structVec[i].circle.getPosition());

		if (dis < 150)
		{


			structVec[i].velocity.x = -(playerObjectStruct.circle.getPosition().x - structVec[i].circle.getPosition().x) * (1.0 * (dis / 100));
			structVec[i].velocity.y = -(playerObjectStruct.circle.getPosition().y - structVec[i].circle.getPosition().y) * (1.0 * (dis / 100));
		}


	}



	for (int i = 0; i < structVec.size(); i++)
		structVec[i].circle.move(structVec[i].velocity * dt);

	playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	/*circle.move(velocity * dt);

	pCircle.move(pVelocity * dt);*/

	for (int i = 0; i < structVec.size(); i++)
	{
		if (structVec[i].circle.getPosition().x + 40 > bounds.x)
		{
			structVec[i].velocity.x = -abs(structVec[i].velocity.x);

			structVec[i].circle.move(structVec[i].velocity * dt);
		}

		if (structVec[i].circle.getPosition().x < 0)
		{

			structVec[i].velocity.x = abs(structVec[i].velocity.x);

			structVec[i].circle.move(structVec[i].velocity * dt);

		}

		if (structVec[i].circle.getPosition().y + 40 > bounds.y)
		{

			structVec[i].velocity.y = -abs(structVec[i].velocity.y);

			structVec[i].circle.move(structVec[i].velocity * dt);

			//velocity.y = -abs(velocity.y);
			//circle.move(velocity * dt);
		}

		if (structVec[i].circle.getPosition().y < 0)
		{

			structVec[i].velocity.y = abs(structVec[i].velocity.y);

			structVec[i].circle.move(structVec[i].velocity * dt);

			//velocity.y = abs(velocity.y);
			//circle.move(velocity * dt);
		}
	}

	if (playerObjectStruct.circle.getPosition().x + 40 > bounds.x)
	{
		playerObjectStruct.velocity.x = -abs(playerObjectStruct.velocity.x);

		playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);
	}

	if (playerObjectStruct.circle.getPosition().x < 0)
	{

		playerObjectStruct.velocity.x = abs(playerObjectStruct.velocity.x);

		playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	}

	if (playerObjectStruct.circle.getPosition().y + 40 > bounds.y)
	{

		playerObjectStruct.velocity.y = -abs(playerObjectStruct.velocity.y);

		playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

		//velocity.y = -abs(velocity.y);
		//circle.move(velocity * dt);
	}

	if (playerObjectStruct.circle.getPosition().y < 0)
	{

		playerObjectStruct.velocity.y = abs(playerObjectStruct.velocity.y);

		playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

		//velocity.y = abs(velocity.y);
		//circle.move(velocity * dt);
	}
	//for (int k = 0; k < structVec.size(); k++)
	//{
	//		for (int q = 0; q < structVec.size(); q++)
	//		{
	//			if (k != q)
	//			{
	//				if (structVec[k].circle.getPosition().x + 40 > structVec[q].circle.getPosition().x)
	//				{
	//					structVec[k].velocity.x = -abs(structVec[k].velocity.x);

	//					structVec[k].circle.move(structVec[k].velocity * dt);
	//				}

	//				if (structVec[k].circle.getPosition().x < structVec[q].circle.getPosition().x)
	//				{

	//					structVec[k].velocity.x = abs(structVec[k].velocity.x);

	//					structVec[k].circle.move(structVec[k].velocity * dt);

	//				}

	//				if (structVec[k].circle.getPosition().y + 40 > structVec[q].circle.getPosition().y)
	//				{

	//					structVec[k].velocity.y = -abs(structVec[k].velocity.y);

	//					structVec[k].circle.move(structVec[k].velocity * dt);

	//					//velocity.y = -abs(velocity.y);
	//					//circle.move(velocity * dt);
	//				}

	//				if (structVec[k].circle.getPosition().y < structVec[q].circle.getPosition().y)
	//				{

	//					structVec[k].velocity.y = abs(structVec[k].velocity.y);

	//					structVec[k].circle.move(structVec[k].velocity * dt);

	//					//velocity.y = abs(velocity.y);
	//					//circle.move(velocity * dt);
	//				}
	//			}
	//		
	//		}				
	//}

	//------------------------------------------------------------------------
	
	//IN THE GAME LOOP WE HAVE TO CALL THE NETWORK MANAGER FUNCTIONS!

		//The example here does the following:
		//Check if the server is full
		//If it isn't continue to check for new connections
		//YOU CAN ADD MORE CONDITIONS!
	if (!server.isServerFull()) {
		server.listenForClients();
	}

	//You have to check every frame or every X time if any of the sockets have received data
	//If they have then you can process afterwards!


	int x, y;
	int vx0 = 0, vy0 = 0, vx1 = 0, vy1 = 0, vx2 = 0, vy2 = 0, vx3 = 0, vy3 = 0;

	sf::Packet sendPacketContainer;
	sf::Packet sendVectorContainer;
	int id = 0;
	x = playerObjectStruct.circle.getPosition().x;
	y = playerObjectStruct.circle.getPosition().y;
	vx0 = structVec[0].circle.getPosition().x;
	vy0 = structVec[0].circle.getPosition().y;
	vx1 = structVec[1].circle.getPosition().x;
	vy1 = structVec[1].circle.getPosition().y;
	vx2 = structVec[2].circle.getPosition().x;
	vy2 = structVec[2].circle.getPosition().y;
	vx3 = structVec[3].circle.getPosition().x;
	vy3 = structVec[3].circle.getPosition().y;

	std::cout << "Current Player Pos: X - " << playerObjectStruct.circle.getPosition().x << ", Y - " << playerObjectStruct.circle.getPosition().y << std::endl;

	sendPacketContainer << x << y << vx0 << vy0 << vx1 << vy1 << vx2 << vy2 << vx3 << vy3;
	server.updateClients(sendPacketContainer);

	
	//std::string vector = "vec";

	//sendVectorContainer << vector << structVec[0].circle.getPosition().x << structVec[0].circle.getPosition().y;
	//	//<< structVec[1].circle.getPosition().x << structVec[1].circle.getPosition().y
	//	//<< structVec[2].circle.getPosition().x << structVec[2].circle.getPosition().y
	//	//<< structVec[3].circle.getPosition().x << structVec[3].circle.getPosition().y;
	//	server.updateClients(sendVectorContainer);
	

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerObjectStruct.circle);
	

	for (int i = 0; i < structVec.size(); i++)
	window->draw(structVec[i].circle);

	//window->draw(pCircle);

	endDraw();
}

// Render level
float Level::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	float distance = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2) * 1.0);
	return distance;
}

void Level::disconnect()
{


	


}