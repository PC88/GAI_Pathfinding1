#pragma once
#include "AIFG\Graph.h"
#include <vector>

class Connection;

class GraphController
{
public:
	GraphController();
	virtual ~GraphController();

	// will return a connection list when refactored
	//Connection* PathfindDijkstra(Graph graph, int start, int end);

	// will return a connection list when refactored
	Connection* PathfindAstar(Graph graph, int start, int end, int heuristic);

	// will return a connection list when refactored
	Connection* PathfindNodeAstar(Graph graph, int start, int end, int heuristic);


	std::vector<int> openList;
	std::vector<int> closedList;
	std::vector<int> totalList;
};

