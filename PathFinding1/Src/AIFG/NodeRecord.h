#pragma once
#include "AIFG\Connection.h"


// this structure is used to keep track of the information
// we need for each node, can be reworked to a stuct later
class NodeRecord
{
public:
	NodeRecord();
	virtual ~NodeRecord();

	int node;
	Connection connection;
	float costSoFar;
	float estimatedTotalCost;
	int nextRecordInList;
};

enum class Category
{
	CLOSED = 0, OPEN = 1, UNVISITED = 2
};

