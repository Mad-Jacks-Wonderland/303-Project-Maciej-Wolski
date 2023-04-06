#include "NetworkServerManager.h"

NetworkServerManager::NetworkServerManager()
{
	//Creates a container to where clients will be stored when connecting for the first time
	newClient = new sf::TcpSocket();
	newClient->setBlocking(false);

	//Start the listening socket
	listener.setBlocking(false);
	if (listener.listen(PORT) != sf::Socket::Done) {
		std::cout << "Error creating listening socket\n";
	}

	isFullFlag = false;

	std::cout << "Server is ready to listen for connections\n";
}

bool NetworkServerManager::isServerFull()
{
	return isFullFlag;
}

void NetworkServerManager::listenForClients()
{
	auto status = listener.accept(*newClient);

	//check if there is a connection to accept, if none stop function
	if (status == sf::Socket::NotReady) {
		//Socket is not ready to accept connections
		//accept will return immediately if there's no pending connection.
		return;
	}

	//Check if there is any errors in accepting a new connection
	if (status != sf::Socket::Done) {
		//DO ERROR HANDLING HERE
		std::cout << "Error in accepting new connection\n";
		return;
	}

	

	//If you reach here, it means a client has been able to connect to our server
	//Now we need to handle the new client and process it
	//The following code will be an example

	//Check if player can actually join the game:
	if (clients.size() > MAX_PLAYERS) {
		//To many clients already, disconnect new client
		newClient->disconnect();
		return;
	}

	//Client can join the game, we will have to give him an ID for sync purposes
	//We will use sfml packets to keep it simple
	//Create a SFML Packet with the ID
	int clientID = clients.size(); //IDs will start at 0!
	sf::Packet idPacket;
	idPacket << clientID;

	//Call the send function with the packet and client to send to
	sendPacketToClient(newClient, idPacket);

	//Assume the client receives the packet
	//We finished processing the new client, now add it to our vector to keep track what clients are currently connected to us (server)
	clients.push_back(newClient);
	std::cout << "New Client has connected\n";

	//Change the isFull Flag
	isFullFlag = clients.size() >= MAX_PLAYERS;

	//Now dont forget, newClient is a TEMPORARY CONTAINER, we need to create a new container to be able to accept more clients!
	newClient = new sf::TcpSocket();
	newClient->setBlocking(false);
}

void NetworkServerManager::sendPacketToClient(sf::TcpSocket* client, sf::Packet packet)
{
	if (client->send(packet) != sf::Socket::Done) {
		//DO ERROR HANDLING HERE
		std::cout << "Error in sending packet to client\n";
		return;
	}
}

//void NetworkServerManager::createPacket(int id, float x, float y)
//{
//	sf::Packet packetContainer;
//	packetContainer >> id >> x >> y;
//		std::cout << "Received Player ID: " << id << "Position: X:" << std::to_string(x) << " Y:" << std::to_string(y) << "\n";
//		
//		for (sf::TcpSocket* client : clients) {
//			sendPacketToClient(client, packetContainer);
//		}
//		
//	
//
//}
//


void NetworkServerManager::disconnect()
{

	for (sf::TcpSocket* client : clients) {
		client->disconnect();
		std::cout << "socket disabled\n";
	}

	listener.close();

	std::cout << "listener disabled\n";

}

void NetworkServerManager::updateClients(sf::Packet packet)
{
	for (sf::TcpSocket* client : clients) {
		client->send(packet);
		//std::cout << "tick\n";
	}
}

//void NetworkServerManager::receivePacket(sf::TcpSocket* client)
//{
//	sf::Packet packetContainer;
//	auto status = client->receive(packetContainer);
//
//	//check if there is a data to receive, if none stop function
//	if (status == sf::Socket::NotReady) {
//		//Socket doesnt have any data to receive
//		return;
//	}
//
//	//Check if there is any errors in receiving data
//	if (status != sf::Socket::Done) {
//		//DO ERROR HANDLING HERE
//		std::cout << "Error in receiving data\n";
//		return;
//	}
//
//	//if (status == sf::Socket::Disconnected) {
//	//	client->disconnect();
//	//	//clients.erase(std::remove(clients.begin(), clients.end(), 8), clients.end());
//	//	std::cout << "client disconnected, terminating connection\n";
//	//	return;
//	//}
//
//				std::string playerName;
//				
//
//				if (packetContainer >> playerID >> playerX >> playerY) {
//					std::cout << "Received Player ID: " << playerID << "Position: X:" << std::to_string(playerX) << " Y:" << std::to_string(playerY) << "\n";
//					sendPacketToClient(client, packetContainer);
//				}
//				
//
//			
//	
//	
//}

