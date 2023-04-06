#pragma once
#include <SFML/Network.hpp>
#include <iostream>

class NetworkServerManager
{
	enum PACKETTYPE {
		NAME,
		POSITION
	};


private:
	const short PORT = 99999;
	const short MAX_PLAYERS = 4;

	sf::TcpListener listener;
	sf::TcpSocket* newClient;

	std::vector<sf::TcpSocket*> clients;

	bool isFullFlag;

	void receivePacket(sf::TcpSocket* client);

public:
	NetworkServerManager();

	bool isServerFull();

	void listenForClients();
	
	void sendPacketToClient(sf::TcpSocket* client, sf::Packet packet); //Call this simple function whenever you to send a packet to a client, you can even use a loop to send something to every client!
	
	void receivePackets();
};

