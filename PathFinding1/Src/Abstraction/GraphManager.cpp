#include "Abstraction\GraphManager.h"
#include <iostream>


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
