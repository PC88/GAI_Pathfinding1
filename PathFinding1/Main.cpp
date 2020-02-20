#include "iostream"


// this contains all needed structs, and data
// pertaining to the algorithms employed on the graph extracted from the boost
// graph library
#include "AIFG/GraphStructures.h" 

// credit to this example for the initial grounding
// https://stackoverflow.com/questions/29496182/read-graphviz-in-boostgraph-pass-to-constructor

// boost libraries
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
#include <libs/graph/src/read_graphviz_new.cpp> // translation unit so it remains header only
#include <boost/graph/graph_utility.hpp>

using namespace boost;

typedef property<graph_name_t, std::string> graph_p;
typedef adjacency_list<vecS, vecS, undirectedS, Vertex, Edge, graph_p> graph_t;


int main()
{
	// Construct an empty graph and prepare the dynamic_property_maps.
	graph_t graph(0);

	dynamic_properties dp(ignore_other_properties);
	dp.property("node_id", get(&Vertex::ID, graph));
	dp.property("pos", get(&Vertex::pos, graph));
	dp.property("fontsize", get(&Vertex::fontsize, graph));
	dp.property("label", get(&Edge::label, graph));

	// Use ref_property_map to turn a graph property into a property map
	boost::ref_property_map<graph_t *, std::string> gname(get_property(graph, graph_name));
	dp.property("AI For Games Graph", gname);

	std::ifstream dot("graph.dot");

	if (read_graphviz(dot, graph, dp, "node_id")) 
	{
		std::cout << "Graph name: '" << get_property(graph, graph_name) << "'\n";
		get_property(graph, graph_name) = "Let's give it a name";
		write_graphviz_dp(std::cout, graph, dp, "node_id");
	}

	std::cout << graph.m_vertices[1].m_property.ID << std::endl;
	std::cout << graph.m_vertices[2].m_property.ID << std::endl;
	std::cout << graph.m_vertices[3].m_property.ID << std::endl;
	std::cout << graph.m_vertices[4].m_property.ID << std::endl;

	graph_t::vertex_iterator vertexIt, vertexEnd;
	graph_t::in_edge_iterator inedgeIt, inedgeEnd;
	graph_t::in_edge_iterator outedgeIt, outedgeEnd;

	tie(vertexIt, vertexEnd) = vertices(graph);
	for (; vertexIt != vertexEnd; ++vertexIt)
	{
		std::cout << "incoming edges for " << *vertexIt << ": ";
		tie(inedgeIt, inedgeEnd) = in_edges(*vertexIt, graph);
		for (; inedgeIt != inedgeEnd; ++inedgeIt)
		{
			std::cout << *inedgeIt << " ";
		}
		std::cout << "\n";
	}
	std::cin.get();
	return 0;
}