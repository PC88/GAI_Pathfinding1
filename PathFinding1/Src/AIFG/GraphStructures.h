#pragma once


struct Vertex // NODE
{
	std::string pos, fontsize;
	unsigned int ID; // cannot be negative for the algorithms to work
};

struct Edge // CONNECTION
{
	std::string label;
	double weight; // perhaps you need this later as well, just an example
	Vertex fromNode;
	Vertex toNodes[4]; // every vertex has 4 connection
};

struct NodeRecord
{
	Vertex node;
	Edge edge;
	double costSoFar;
	double estimatedTotalCost;
	NodeRecord* nextRecordInList;

	enum class Category
	{
		CLOSED = 0, OPEN = 1, UNVISITED = 2
	};
};


struct Heuristic
{
	Vertex goalNode;

	//float estimate(Vertex toNode, Vertex fromNode)
	//{
	//	
	//}

	//float estimate(int fromNode)
	//{
	//	return estimate(fromNode, goalNode);
	//}
};