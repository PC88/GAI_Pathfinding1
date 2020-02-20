#pragma once


struct Vertex // NODE
{
	std::string pos, fontsize;
	unsigned int ID; // cannot be negative for the algorithms to work
};

struct Edge // CONNECTION
{
	std::string label;
	double weight; // perhaps you need this later as well, just an example
};