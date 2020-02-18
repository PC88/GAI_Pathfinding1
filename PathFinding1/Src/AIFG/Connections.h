#pragma once
class Connections
{
public:
	Connections();
	virtual ~Connections();

	// the node that this connections came from
	int* fromNode;

	// the node this connection leads to
	// rename as graph is undirected and has multiple connecting nodes
	// so there can be multiple nodes to path to. 
	int* toNodes;

	// the non-negative cost of this connection
	float getCost();

};

