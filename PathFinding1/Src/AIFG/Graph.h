#pragma once

// forward dec for better build times
class Connection;

class Graph
{
public:
	Graph();
	virtual ~Graph();

	int nodeArray[63];


	// An array of connections outgoing from the given node.
	Connection* getConnections(int fromNode);
};

