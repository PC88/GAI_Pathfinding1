#include "AIFG\GraphController.h"


GraphController::GraphController()
{
}


GraphController::~GraphController()
{
}

//Connection* GraphController::PathfindDijkstra(Graph graph, int start, int end)
//{
//	////Init the record for the start node
//	//NodeRecord startRecord;
//	//startRecord.node = start;
//	////startRecord.connection = nullptr;
//	//startRecord.costSoFar = 0;
//
//	//// initialize the open and closed lists
//	//openList.emplace_back(start);
//
//	//// iterate through processing each node.
//	//while (openList.size() > 0)
//	//{
//	//	// find the smallest element in the open list.
//	//	NodeRecord current;
//	//}
//
//	//// temp will be removed
//	//Connection* connection = nullptr;
//	//return connection;
//
//	///// Pseudo code for algorithm
//	// DIJKSTRA
//
//
//}

Connection * GraphController::PathfindAstar(Graph graph, int start, int end, int heuristic)
{
	/// Pseudo code for algorithm
	// A*

	/// this structure is used to keep track of the
	// information we need for each node
	// class NodeRecord:
	//	node: Node
	//	connection: Connection
	//	costSoFar: float
	//	estimatedTotalCost: float

	/// initialize the record for the start node.
	// startRecord = new NodeRecord();
	// startRecord.node
	// startRecord.connection = null
	// startRecord.costSoFar = 0
	// startRecord.estimatedTotalCost = heuristic.estimate(start)

	/// initialize the open and closed lists
	// open = new PathFindingList()
	// open += startRecord
	// closed = new PathFindingList()

	/// Iterate through processing each node.
	// while(length(open) > 0:
	//		# Find the smallest element in the open list (using the
	//		# estimated total cost)
	//		current = open.smallestElement()

	//		# If it is the goal node, then terminate.
	//		 if current.node == goal:
	//			break

	//		# Otherwise get its outgoing connections.
	//		connections = graph.getConnections(current)

	//		# Loop through each connection in turn.
	//		for connection in connections:
	//			# Get the cost estimate for the node.
	//			endNode = connections.getToNode()
	//			endNodeCost = current.costSoFar + connection.getCost()
	
	//			# If the node is closed we may have to skip, or remove it
	//			# from the closed list.
	//			if closed.contains(endNode)
	//				# Here we find the record in the closed list
	//				# corresponding to the endNode.
	//				endNodeRecord = closed.find(endNode)
	
	//				# if we dident find a shorter route, skip.
	//				if endNodeRecord.costSoFar <= endNodeCost:
	//					continue
	
	//				# Otherwise remove it from the closed list.
	//				closed -= endNodeRecord

	//				# We can use the node`s old cost values to calculate
	//				# its heuristic without calling the possibility expensive
	//				# heuristic function
	//				endNodeHeuristic = endNodeRecord.estimatedTotalCost - endNodeRecord.costSoFar

	//			# skip if node is open and we`ve not found a better
	//			# route
	//			else if open.contains(endNode):
	//				# here we find the record in the open list
	//				# corresponding to the endNode.
	//				endNodeRecord = open.find(endNode)

	//				# if our route is no better then skip.
	//				if endNodeRecord.costSoFar <= endNodeCost:
	//					continue

	//				# Again, we can calculate its heuristic.
	//				endNodeHeuristic = endNodeRecord.cost - endNodeRecord.costSoFar

	//			# Otherwise we know we`ve got an unvisited node, so make a 
	//			# record of it
	//			else:
	//				endNodeRecord = new NodeRecord()
	//				endNodeRecord.node = endNode
	
	//				# We`ll need to calculate the heuristic value using
	//				# the function, since we don`t have an existing record
	//				# to use.
	//				endNodeHeuristic = heuristic.estimate(endNode)

	//			# We`re here if we need to update the node. Update the
	//			# cost, estimate and connection.
	//			endNodeRecord.cost = endNodeCost
	//			endNodeRecord.connection = connection
	//			endNodeRecord.estimatedTotalCost = endNodeCost + endNodeHeuristic

	//			# And add it to the open list.
	//			if not open.contains(endNode):
	//				open += endNodeRecord

	//		# We`ve finished looking at the connections for the current
	//		# node, so add it to the closed list and remove it from the
	//		# open list.
	//		open -= current
	//		closed += current

	//	# We`re here if we`ve either found the goal, or if we`ve no more
	//	# nodes to search, find which.
	//	if current.node != goal:
	//		# We`ve run out of nodes without finding the goal, so there`s
	//		# no solution.
	//		return null
	// else:
	//		# Compile the list of connections in the path.
	//		path = []
	
	//		# Work back along the path, accumulating connections.
	//		while current.node != start:
	//			path += current.connection
	//			current = current.connection.getFromNode()


	//		# Reverse the path, and return it.
	//		return reverse(path);
	return nullptr;
}

Connection * GraphController::PathfindNodeAstar(Graph graph, int start, int end, int heuristic)
{
	/// Pseudo code for algorithm
	// Node Array A*

	return nullptr;
}
