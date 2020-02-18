#pragma once
class Connections
{
public:
	Connections();
	virtual ~Connections();

	// the node that this connections came from
	int* fromNode;

	// the node this connection leads to
	int* toNode;

	// the non-negative cost of this connection
	float getCost();

};

