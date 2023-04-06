#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	sf::Vector2u bounds = window->getSize();;

	//sf::Vector2i pos = static_cast<sf::Vector2i>(circle.getPosition());

	// initialise game objects

	
	playerObjectStruct.id = 0;

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
		//newObjectStruct.circle.setPosition((pos), (150));
		newObjectStruct.circle.setPosition((pos * i), (75 * i));
		newObjectStruct.circle.setFillColor(sf::Color::Blue);
		newObjectStruct.circle.setOutlineColor(sf::Color::Red);
		newObjectStruct.circle.setOutlineThickness(2.0f);

		newObjectStruct.velocity.x = 0.0f;
		newObjectStruct.velocity.y = 0.0f;

		newObjectStruct.objectType = OBJECT;

		structVec.push_back(newObjectStruct);
	}

	//structVec.push_back();

	/*circle.setRadius(20);
	circle.setPosition((100), (100));
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.0f);*/

	/*pCircle.setRadius(20);
	pCircle.setPosition((100), (100));
	pCircle.setFillColor(sf::Color::Red);
	pCircle.setOutlineColor(sf::Color::Blue);
	pCircle.setOutlineThickness(2.0f);*/

	/*velocity.x = -28.0f;
	velocity.y = 18.0f;

	pVelocity.x = 0.0f;
	pVelocity.y = 0.0f;*/


	if (socket.connect("127.0.0.1", 99999) != sf::Socket::Done) {
		std::cout << "Error connecting to server\n";
	}

	
	sf::Packet idPacket;
	socket.receive(idPacket);
	if (idPacket >> clientID) {
		std::cout << "Received ID: " << std::to_string(clientID) << " from server" << "\n";
	}

	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Escape))
	{
		socket.disconnect();
		std::cout << "socket disconnected\n";
	}

	
}

// Update game objects
void Level::update(float dt)
{

	sf::Vector2u bounds = window->getSize();

	//sf::Vector2i pos = static_cast<sf::Vector2i>(circle.getPosition());

	//sf::Vector2i pPos = static_cast<sf::Vector2i>(pCircle.getPosition());

	//float distance = sqrt(pow(pCircle.getPosition().x - circle.getPosition().x, 2) + pow(pCircle.getPosition().y - circle.getPosition().y, 2) * 1.0);

	//for (int i = 0; i < structVec.size(); i++)
	//{


	//	float dis = distance(playerObjectStruct.circle.getPosition(), structVec[i].circle.getPosition());

	//	if (dis < 150)
	//	{

	//		//velocity.x = (pCircle.getPosition().x + circle.getPosition().x) * ();
	//		//velocity.y = (pCircle.getPosition().y + circle.getPosition().y) * 0.5;

	//		structVec[i].velocity.x = -(playerObjectStruct.circle.getPosition().x - structVec[i].circle.getPosition().x) * (1.0 * (dis / 100));
	//		structVec[i].velocity.y = -(playerObjectStruct.circle.getPosition().y - structVec[i].circle.getPosition().y) * (1.0 * (dis / 100));
	//	}
	//	//else
	//	//{
	//	//	structVec[i].velocity.x = (playerObjectStruct.circle.getPosition().x - structVec[i].circle.getPosition().x) * (1.0 * (dis / 100));
	//	//	structVec[i].velocity.y = (playerObjectStruct.circle.getPosition().y - structVec[i].circle.getPosition().y) * (1.0 * (dis / 100));
	//	//	//velocity.x = (pCircle.getPosition().x - circle.getPosition().x) * 0.5;
	//	//	//velocity.y = (pCircle.getPosition().y - circle.getPosition().y) * 0.5;

	//	//}


	//	//for (int k = 1; k < structVec.size(); k++)
	//	//{
	//	//	for (int q = 1; q < structVec.size(); q++)
	//	//	{
	//	//		if (k != q)
	//	//		{

	//	//			float dist = distance(structVec[k].circle.getPosition(), structVec[q].circle.getPosition());

	//	//			if (dist < 50)
	//	//			{

	//	//				//velocity.x = (pCircle.getPosition().x + circle.getPosition().x) * ();
	//	//				//velocity.y = (pCircle.getPosition().y + circle.getPosition().y) * 0.5;

	//	//				structVec[k].velocity.x = -(structVec[0].circle.getPosition().x - structVec[q].circle.getPosition().x) * (1.0 * (dist / 100));
	//	//				structVec[k].velocity.y = -(structVec[0].circle.getPosition().y - structVec[q].circle.getPosition().y) * (1.0 * (dist / 100));
	//	//			}
	//	//			else
	//	//			{
	//	//				structVec[k].velocity.x = (structVec[0].circle.getPosition().x - structVec[q].circle.getPosition().x) * (1.0 * (dist / 100));
	//	//				structVec[k].velocity.y = (structVec[0].circle.getPosition().y - structVec[q].circle.getPosition().y) * (1.0 * (dist / 100));
	//	//				//velocity.x = (pCircle.getPosition().x - circle.getPosition().x) * 0.5;
	//	//				//velocity.y = (pCircle.getPosition().y - circle.getPosition().y) * 0.5;

	//	//			}

	//	//		}
	//	//			
	//	//		
	//	//	}
	//	//}

	//}



	////for (int i = 0; i < structVec.size(); i++)
	//	structVec[i].circle.move(structVec[i].velocity * dt);

	//playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	///*circle.move(velocity * dt);

	//pCircle.move(pVelocity * dt);*/

	//for (int i = 0; i < structVec.size(); i++)
	//{
	//	if (structVec[i].circle.getPosition().x + 40 > bounds.x)
	//	{
	//		structVec[i].velocity.x = -abs(structVec[i].velocity.x);

	//		structVec[i].circle.move(structVec[i].velocity * dt);
	//	}

	//	if (structVec[i].circle.getPosition().x < 0)
	//	{

	//		structVec[i].velocity.x = abs(structVec[i].velocity.x);

	//		structVec[i].circle.move(structVec[i].velocity * dt);

	//	}

	//	if (structVec[i].circle.getPosition().y + 40 > bounds.y)
	//	{

	//		structVec[i].velocity.y = -abs(structVec[i].velocity.y);

	//		structVec[i].circle.move(structVec[i].velocity * dt);

	//		//velocity.y = -abs(velocity.y);
	//		//circle.move(velocity * dt);
	//	}

	//	if (structVec[i].circle.getPosition().y < 0)
	//	{

	//		structVec[i].velocity.y = abs(structVec[i].velocity.y);

	//		structVec[i].circle.move(structVec[i].velocity * dt);

	//		//velocity.y = abs(velocity.y);
	//		//circle.move(velocity * dt);
	//	}
	//}

	//if (playerObjectStruct.circle.getPosition().x + 40 > bounds.x)
	//{
	//	playerObjectStruct.velocity.x = -abs(playerObjectStruct.velocity.x);

	//	playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);
	//}

	//if (playerObjectStruct.circle.getPosition().x < 0)
	//{

	//	playerObjectStruct.velocity.x = abs(playerObjectStruct.velocity.x);

	//	playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	//}

	//if (playerObjectStruct.circle.getPosition().y + 40 > bounds.y)
	//{

	//	playerObjectStruct.velocity.y = -abs(playerObjectStruct.velocity.y);

	//	playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	//	//velocity.y = -abs(velocity.y);
	//	//circle.move(velocity * dt);
	//}

	//if (playerObjectStruct.circle.getPosition().y < 0)
	//{

	//	playerObjectStruct.velocity.y = abs(playerObjectStruct.velocity.y);

	//	playerObjectStruct.circle.move(playerObjectStruct.velocity * dt);

	//	//velocity.y = abs(velocity.y);
	//	//circle.move(velocity * dt);
	//}
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
	
	//int enumID = 1; //PACKETTYPE ENUM, 0 corresponds to NAME
	//std::string playerName = "Player " + std::to_string(randomNumber);
	//sf::Packet namePacket;
	////namePacket << enumID << playerName;
	//namePacket << enumID << randomPos1 << randomPos2;
	//socket.send(namePacket);
	//std::cout << "Sent to Server -  ID-: " << enumID << ", Position: X:" << std::to_string(randomPos1) << ", Y:" << std::to_string(randomPos2) << "\n";

//	int playerX, playerY, playerID;
//	//recieve data
//	sf::Packet packetContainer;;
//	socket.receive(packetContainer);
////	std::cout << "Current Data - ID-: " << playerID << ", Position: X:" << std::to_string(playerX) << ", Y:" << std::to_string(playerY) << "\n";
//	if (packetContainer >> playerID >> playerX >> playerY) {
//		std::cout << "Received From Server - ID-: " << playerID << ", Position: X:" << std::to_string(playerX) << ", Y:" << std::to_string(playerY) << "\n";
//
//		if (playerID == playerObjectStruct.id)
//		{
//			playerObjectStruct.circle.setPosition(playerX, playerY);
//		}
//	}

	sf::Packet posPacket;

	sf::Packet vectorPosPacket;
	std::string vec;
	int x = 0, y = 0, index = 0;
		
		int vx0 = 0, vy0 = 0, vx1 = 0, vy1 = 0, vx2 = 0, vy2 = 0, vx3 = 0, vy3 = 0;
	
	int enumID = 1;



	/*sf::Packet sendPacketContainer;
	int id = 0;
	x = x + 5;
	sendPacketContainer >> enumID >> x >> y;
	socket.send(sendPacketContainer);*/


	socket.receive(posPacket);
	if (posPacket >> x >> y >> vx0 >> vy0 >> vx1 >> vy1 >> vx2 >> vy2 >> vx3 >> vy3) {
		std::cout << "Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
		//sf::Packet sendPacketContainer;
		//int id = 0;
	   // x = x + 5;
		playerObjectStruct.circle.setPosition(x, y);
		structVec[0].circle.setPosition(vx0, vy0);
		structVec[1].circle.setPosition(vx1, vy1);
		structVec[2].circle.setPosition(vx2, vy2);
		structVec[3].circle.setPosition(vx3, vy3);
	   // socket.send(sendPacketContainer);
	}

		//if (posPacket >> vx0 >> vy0 >> vx1 >> vy1 >> vx2 >> vy2 >> vx3 >> vy3)
		//{
		//	//socket.receive(posPacket);

		//	//std::cout << "Circle number : " << index << ", Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
		//	//sf::Packet sendPacketContainer;
		//	//int id = 0;
		//   // x = x + 5;
		//	structVec[0].circle.setPosition(vx0, vy0);
		//	structVec[1].circle.setPosition(vx1, vy1);
		//	structVec[2].circle.setPosition(vx2, vy2);
		//	structVec[3].circle.setPosition(vx3, vy3);
		//	// socket.send(sendPacketContainer);
		//}

		//if (posPacket >> vec >> vx0 >> vy0)
		//{
		//	//socket.receive(posPacket);

		//	//std::cout << "Circle number : " << index << ", Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
		//	//sf::Packet sendPacketContainer;
		//	//int id = 0;
		//   // x = x + 5;
		//	structVec[0].circle.setPosition(vx0, vy0);
		//	// socket.send(sendPacketContainer);
		//}

	//system("CLS");

	std::cout << "Player Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
	std::cout << "Position: X:" << std::to_string(vx0) << " Y:" << std::to_string(vy0) << "\n";
	/*std::cout << "Position: X:" << std::to_string(vx1) << " Y:" << std::to_string(vy1) << "\n";
	std::cout << "Position: X:" << std::to_string(vx2) << " Y:" << std::to_string(vy2) << "\n";
	std::cout << "Position: X:" << std::to_string(vx3) << " Y:" << std::to_string(vy3) << "\n";*/


	//if (posPacket >> index >> x >> y) 
	//{
	//	std::cout << "Circle number : " << index << ", Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
	//	//sf::Packet sendPacketContainer;
	//	//int id = 0;
	//   // x = x + 5;
	//	structVec[index].circle.setPosition(x, y);
	//	// socket.send(sendPacketContainer);
	//}
	


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


