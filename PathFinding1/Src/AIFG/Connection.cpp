#include "AIFG\Connection.h"



Connection::Connection()
{
}


Connection::~Connection()
{
}

float Connection::getCost()
{
	return 0.0f;
}

int * Connection::getFromeNode()
{
	return fromNode;
}

int * Connection::getToNode()
{
	return toNodes;
}
