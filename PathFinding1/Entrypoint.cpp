
//
//=======================================================================
// Copyright (c) 2004 Kristopher Beevers
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
//

#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/random.hpp>
#include <boost/graph/graphviz.hpp>
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

// abstraction of base code
#include "Abstraction/Heuristic.h"
#include "Abstraction/Visitor.h"
#include "Abstraction/WeightMap.h"

#include "Abstraction/GraphManager.h"

using namespace boost;
using namespace std;

int main(int argc, char **argv)
{

	// specify some types
	typedef adjacency_list<listS, vecS, undirectedS, no_property,
		property<edge_weight_t, cost> > mygraph_t;
	typedef mygraph_t::vertex_descriptor vertex;
	typedef property_map<mygraph_t, edge_weight_t>::type WeightMap;
	typedef mygraph_t::edge_descriptor edge_descriptor;
	typedef std::pair<unsigned int, unsigned int> edge; // changed to unsigned int as there is no negative edge values



	edge edge_array[] = { 
	  edge(Zero, Three), edge(Zero, Seven),edge(Zero, Six), edge(Zero, Thirteen),
	  edge(One, Four), edge(One, Five),edge(One, Nine), edge(One,Ten),
	  edge(Two, Eleven), edge(Two, Five),edge(Two, Ten), edge(Two, Twelve),
      edge(Three, Six), edge(Three, Seven),edge(Three, Eight), 
	  edge(Four, Nine), edge(Four, Five),edge(Four, Eight),
	  edge(Five, Ten), 
	  edge(Six, Eight), edge(Six, Thirteen),
	  edge(Seven, Thirteen), edge(Seven, Eight),
	  edge(Nine, Thirteen), edge(Nine, Fifteen),
	  edge(Ten, Fifteen),
	  edge(Eleven, Fourteen), edge(Eleven, Twelve),edge(Eleven, TwentyTwo),
	  edge(Twelve, Fourteen), edge(Twelve, TwentyTwo),
	  edge(Fourteen, TwentyTwo), edge(Fourteen, TwentyFive),
	  edge(Fifteen, Eighteen), edge(Fifteen, Sixteen),
	  edge(Sixteen, Twenty), edge(Sixteen, Eighteen),edge(Sixteen, Nineteen),
	  edge(Seventeen,TwentyThree), edge(Seventeen,TwentySix),edge(Seventeen, TwentySeven),
	  edge(Eighteen, TwentyOne), edge(Eighteen,Twenty),
	  edge(Nineteen, TwentyFour), edge(Nineteen,Twenty),edge(Nineteen,TwentyNine),
	  edge(Twenty, TwentyFour), 
	  edge(TwentyOne, TwentyTwo), edge(TwentyOne, TwentyFour),edge(TwentyOne, TwentyFive),
	  edge(TwentyThree, TwentyEight), edge(TwentyThree, TwentySix),edge(TwentyThree, TwentySeven), 
	  edge(TwentyFour, TwentyNine), 
	  edge(TwentyFive, ThirtyTwo), edge(TwentyFive, ThirtyFive),
	  edge(TwentySix, TwentySeven), edge(TwentySix, Thirty),
	  edge(TwentySeven, Thirty), 
	  edge(TwentyEight, ThirtySix), edge(TwentyEight, Thirty),
	  edge(TwentyNine, ThirtyOne), edge(TwentyNine, Thirty),
	  edge(ThirtyOne, ThirtySeven), edge(ThirtyOne, ThirtyFour),edge(ThirtyOne, FortyTwo),
	  edge(ThirtyThree, ThirtyEight), edge(ThirtyThree, ThirtyNine),edge(ThirtyThree, ThirtyFour), edge(ThirtyThree, FortyThree),
	  edge(ThirtyFour, FortyThree), edge(ThirtyFour, ThirtySeven),
	  edge(ThirtyFive, FortyFive), edge(ThirtyFive, FortyFour),
	  edge(ThirtySix, Forty), edge(ThirtySix, FortyTwo),edge(ThirtySix,ThirtySeven), 
	  edge(ThirtySeven, FortyTwo), 
	  edge(ThirtyEight, ThirtyNine), edge(ThirtyEight, FortyOne),edge(ThirtyEight, FortySeven), 
	  edge(ThirtyNine, FortyOne), edge(ThirtyNine, FortySeven),
	  edge(Forty, FortyTwo), edge(Forty, FiftySix),edge(Forty, FiftyFive), 
	  edge(FortyOne, FortyNine), edge(FortyOne, FortyFour),
	  edge(FortyThree, FortySeven), edge(FortyThree, Fifty),
	  edge(FortyFour, FortyFive), 
	  edge(FortyFive, FortySix), 
	  edge(FortySix, FiftyThree), edge(FortySix, FiftyOne),edge(FortySix, FiftyNine), 
	  edge(FortySeven, FortyEight),
	  edge(FortyEight, Fifty), edge(FortyEight, FortyNine),edge(FortyEight, FiftyOne),
	  edge(FortyNine, FiftyOne), edge(FortyNine, Fifty),
	  edge(Fifty, FiftyTwo),
	  edge(FiftyOne, FiftyThree), 
	  edge(FiftyTwo, FiftyFour),edge(FiftyTwo, Sixty), edge(FiftyTwo, FiftyEight),
	  edge(FiftyThree, FiftyNine), edge(FiftyThree, SixtyThree),
	  edge(FiftyFour, Sixty), edge(FiftyFour, FiftyEight), edge(FiftyFour, FiftyFive),
	  edge(FiftyFive, FiftySeven), edge(FiftyFive, FiftySix),
	  edge(FiftySix, FiftySeven), edge(FiftySix, FiftyEight),
	  edge(FiftySeven, FiftyEight), edge(FiftySeven, Sixty),
	  edge(FiftyNine, SixtyThree), edge(FiftyNine, SixtyTwo),
	  edge(Sixty, SixtyOne),
	  edge(SixtyOne, SixtyTwo), edge(SixtyOne, SixtyThree),
	  edge(SixtyTwo, SixtyThree) 

	};
	unsigned int num_edges = sizeof(edge_array) / sizeof(edge);


	// set start and goal 
	vertex start = 0;
	vertex goal = 60;
	std::cout << "Start vertex: " << GraphManager::instance().name[start] << std::endl;
	std::cout << "Goal vertex: " << GraphManager::instance().name[goal] << std::endl;

	// create graph
	mygraph_t g_Graph(N);
	WeightMap weightmap = get(edge_weight, g_Graph);
	for (std::size_t j = 0; j < num_edges; ++j) 
	{
		edge_descriptor e; bool inserted;
		boost::tie(e, inserted) = add_edge(edge_array[j].first,
			edge_array[j].second, g_Graph);
		weightmap[e] = GraphManager::instance().weights[j];
	}

	vector<mygraph_t::vertex_descriptor> descVector(num_vertices(g_Graph));
	vector<cost> costVector(num_vertices(g_Graph));
	try 
	{
		// call astar named parameter interface
		astar_search_tree
		(g_Graph, start,
			distance_heuristic<mygraph_t, cost, Position*>
			(GraphManager::instance().positions, goal),
			predecessor_map(make_iterator_property_map(descVector.begin(), get(vertex_index, g_Graph))).
			distance_map(make_iterator_property_map(costVector.begin(), get(vertex_index, g_Graph))).
			visitor(astar_goal_visitor<vertex>(goal)));
	}
	catch (found_goal fg) 
	{ // found a path to the goal
		list<vertex> shortest_path;
		for (vertex v = goal;; v = descVector[v]) 
		{
			shortest_path.push_front(v);
			if (descVector[v] == v)
				break;
		}
		cout << "Shortest path from " << GraphManager::instance().name[start] << " to "
			<< GraphManager::instance().name[goal] << ": ";
		list<vertex>::iterator spi = shortest_path.begin();
		cout << GraphManager::instance().name[start];
		for (++spi; spi != shortest_path.end(); ++spi)
		{
			cout << " -> " << GraphManager::instance().name[*spi];
		}
		cout << endl << "Total travel cost: " << costVector[goal] << endl;

		std::cin.get();
		return 0;
	}

	cout << "Didn't find a path from " << GraphManager::instance().name[start] << "to"
		<< GraphManager::instance().name[goal] << "!" << endl;

	
	return 0;
}
