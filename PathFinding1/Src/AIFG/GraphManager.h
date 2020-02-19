#pragma once
#include "AIFG\Graph.h"
#include <vector>

class Connection;

class GraphManager
{
public:
	GraphManager();
	virtual ~GraphManager();

	Connection* PathfindDijkstra(Graph graph, int start, int end);

	std::vector<int> openList;
	std::vector<int> closedList;
};

