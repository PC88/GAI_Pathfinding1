#pragma once
class Connection
{
public:
	Connection();
	virtual ~Connection();

	// the node that this connections came from
	int* fromNode;

	// the node this connection leads to
	// rename as graph is undirected and has multiple connecting nodes
	// so there can be multiple nodes to path to. 
	int* toNodes;

	float cost;

	// the non-negative cost of this connection
	float getCost();

	// still potential refactors
	int* getFromeNode();

	// still potential refactors
	int* getToNode();

};

