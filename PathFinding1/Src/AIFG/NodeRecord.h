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
};

