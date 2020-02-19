#pragma once
class Heuristic
{
public:
	Heuristic();
	virtual ~Heuristic();

	// Stores the goal node that this heuristic is estimating for.
	int goalNode;

	// Estimated cost to kove between any two nodes.
	float estimate(int toNode, int fromNode);

	// an estimated cost to reach the goal from the given node.
	float estimate(int fromNode);
};

