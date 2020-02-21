#include "Abstraction\GraphManager.h"


GraphManager& GraphManager::instance()
{
	static GraphManager _self;
	return _self;
}

GraphManager::GraphManager()
{
}


GraphManager::~GraphManager()
{
}
