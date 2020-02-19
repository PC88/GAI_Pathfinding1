#include "AIFG\GraphManager.h"
#include "AIFG\NodeRecord.h"


GraphManager::GraphManager()
{
}


GraphManager::~GraphManager()
{
}

Connection* GraphManager::PathfindDijkstra(Graph graph, int start, int end)
{
	//Init the record for the start node
	NodeRecord startRecord;
	startRecord.node = start;
	//startRecord.connection = nullptr;
	startRecord.costSoFar = 0;

	// initialize the open and closed lists
	openList.emplace_back(start);

	// iterate through processing each node.
	while (openList.size() > 0)
	{
		// find the smallest element in the open list.
		NodeRecord current;
	}

	// temp will be removed
	Connection* connection = nullptr;
	return connection;
}
