
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
	typedef property_map<mygraph_t, edge_weight_t>::type WeightMap;
	typedef mygraph_t::vertex_descriptor vertex;
	typedef mygraph_t::edge_descriptor edge_descriptor;
	typedef std::pair<int, int> edge;

	
	const char *name[] = 
	{
	  "0", "1", "2", "3",
	  "4", "5", "6", "7", "8",
	  "9", "10", "11", "12"
	   "13", "14", "15", "16",
	  "17", "18", "19", "20", "21",
	  "22", "23", "24", "25",
		 "26", "27", "28", "29",
	  "30", "31", "32", "33", "34",
	  "35", "36", "37", "38",
		 "39", "40", "41", "42",
	  "43", "44", "45", "46", "47",
	  "48", "48", "49", "50",
	"51", "52", "53", "54",
	  "55", "56", "57", "58", "59",
	  "60", "61", "62", "63"
	};

	// positions from the file used in the Heuristic distance
	Position positions[] = 
	{  
	  {165, 0}, {390, 0}, {495, 0}, // 0, 1, 2
	  {270, 15}, {360, 15}, {420, 45}, // 3, 4, 5
	  {300, 60}, {240, 75}, {330, 75}, // 6, 7, 8
	  {345, 75}, {435, 75}, {525, 75}, // 9, 10, 11
	  {570, 75}, {300, 105}, {555, 105}, // 12, 13, 14
	  {390, 120}, {315, 135}, {60, 150}, // 15, 16, 17
	  {375, 150}, {270, 165}, {300, 180}, // 18, 19, 20
	  {435, 195}, {570, 195}, {45, 225}, // 21, 22, 23
	  {285, 225}, {585, 225}, {120, 240}, // 24, 25, 26
	  {165, 240}, {45, 270}, {255, 270}, // 27, 28, 29
	  {180, 285}, {195, 315}, {525, 330}, // 30, 31, 32
	  {345, 345}, {270, 360}, {525, 360}, // 33, 34, 35
	  {60, 375}, {165, 375}, {390, 375}, // 36, 37, 38
	  {405, 375}, {75, 405}, {435, 405}, // 39, 40, 41
	  {135, 420}, {315, 420}, {480, 420}, // 42, 43, 44
	  {510, 420}, {570, 420}, {360, 435}, // 45, 46, 47
	  {375, 450}, {435, 450}, {345, 465}, // 48, 49, 50
	  {465, 480}, {285, 495}, {555, 495}, // 51, 52, 53
	  {270, 525}, {150, 540}, {90, 555}, // 54, 55, 56
	  {120, 555}, {210, 555}, {570, 555}, // 57, 58, 59
	  {270, 570}, {420, 570}, {435, 570},  // 60, 61, 62
	  {495, 570} // 63
	};
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
	cost weights[] = 
	{ // in order from the list above top to bottom
	  106, 106, 147, 171,		//0
	  33, 54, 87, 87,			//1
	  80, 87, 96, 106,			//2
	  54, 67, 84,				//3
	  61, 67, 67,				//4
	  33,						//5
	  33, 45,					//6 
	  67, 90,					//7
	  54, 63,					//9
	  63,						//10
	  42, 45, 128,				//11
	  33, 120,					//12
	  91, 123,					//14
	  33, 76,					//15
	  47, 54, 61,				//16
	  76, 108, 120, 138,		//17
	  75, 80,					//18
	  33, 61, 106,				//19
	  47,						//20
	  135, 152, 152,			//21
	  45, 76, 120,				//23
	  54,						//24
	  120, 147,					//25
	  45, 75,					//26
	  47,						//27
	  106, 135,					//28
	  75, 76,					//29
	  67, 87, 120,				//31
	  30, 91, 100,				//32
	  54, 67, 76, 80,			//33
	  75, 106,					//34
	  61, 75,					//35
	  33, 87, 105,				//36
	  54,						//37
	  15, 54, 67,				//38
	  42, 75,					//39
	  61, 150, 154,				//40
	  45, 47,					//41
	  47, 54,					//43
	  30,						//44
	  60,						//45
	  76, 120, 135,				//46
	  21,						//47
	  33, 60, 94,				//48
	  42, 91,					//49
	  67,						//50
	  91,						//51
	  33, 76, 96,				//52
	  61,						//53
	  45, 67, 120,				//54
	  33, 61,					//55
	  30, 120,					//56
	  90, 150,					//57
	  76, 135,					//59
	  150,						//60
	  15, 75,					//61
	  60,						//62
	};


	// create graph
	mygraph_t g_Graph(N);
	WeightMap weightmap = get(edge_weight, g_Graph);
	for (std::size_t j = 0; j < num_edges; ++j) 
	{
		edge_descriptor e; bool inserted;
		boost::tie(e, inserted) = add_edge(edge_array[j].first,
			edge_array[j].second, g_Graph);
		weightmap[e] = weights[j];
	}


	// set start and goal 
	vertex start = 0; 
	vertex goal = 60; 


	cout << "Start vertex: " << name[start] << endl;
	cout << "Goal vertex: " << name[goal] << endl;



	vector<mygraph_t::vertex_descriptor> p(num_vertices(g_Graph));
	vector<cost> d(num_vertices(g_Graph));
	try {
		// call astar named parameter interface
		astar_search_tree
		(g_Graph, start,
			distance_heuristic<mygraph_t, cost, Position*>
			(positions, goal),
			predecessor_map(make_iterator_property_map(p.begin(), get(vertex_index, g_Graph))).
			distance_map(make_iterator_property_map(d.begin(), get(vertex_index, g_Graph))).
			visitor(astar_goal_visitor<vertex>(goal)));
	}
	catch (found_goal fg) { // found a path to the goal
		list<vertex> shortest_path;
		for (vertex v = goal;; v = p[v]) {
			shortest_path.push_front(v);
			if (p[v] == v)
				break;
		}
		cout << "Shortest path from " << name[start] << " to "
			<< name[goal] << ": ";
		list<vertex>::iterator spi = shortest_path.begin();
		cout << name[start];
		for (++spi; spi != shortest_path.end(); ++spi)
			cout << " -> " << name[*spi];
		cout << endl << "Total travel cost: " << d[goal] << endl;

		std::cin.get();
		return 0;
	}

	cout << "Didn't find a path from " << name[start] << "to"
		<< name[goal] << "!" << endl;

	
	return 0;

}
