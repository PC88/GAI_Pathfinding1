#pragma once


// container for Positions on the graph
struct Position
{
	// unisgned as there are no - posiitons in the graph
	unsigned int y, x; // Cartesian X/Y
};

// simple typedef for cost representing weights
typedef float cost;

// specify data
// 63 nodes in the graph 
enum nodes
{
	Zero, One, Two, Three, Four, Five, Six,
	Seven, Eight, Nine, Ten, Eleven, Twelve,
	Thirteen, Fourteen, Fifteen, Sixteen, Seventeen,
	Eighteen, Nineteen, Twenty, TwentyOne, TwentyTwo, TwentyThree,
	TwentyFour, TwentyFive, TwentySix, TwentySeven, TwentyEight, TwentyNine,
	Thirty, ThirtyOne, ThirtyTwo, ThirtyThree, ThirtyFour, ThirtyFive, ThirtySix,
	ThirtySeven, ThirtyEight, ThirtyNine, Forty, FortyOne, FortyTwo, FortyThree,
	FortyFour, FortyFive, FortySix, FortySeven, FortyEight, FortyNine, Fifty,
	FiftyOne, FiftyTwo, FiftyThree, FiftyFour, FiftyFive, FiftySix, FiftySeven,
	FiftyEight, FiftyNine, Sixty, SixtyOne, SixtyTwo, SixtyThree,
	N
};

class GraphManager
{

	static GraphManager& instance();

	GraphManager(GraphManager const&) = delete;
	void operator=(GraphManager const&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
		//       C++ book, that deleted functions should generally
		//       be public as it results in better error messages
		//       due to the compilers behavior to check accessibility
		//       before deleted status
		//       this probably wont matter here but dose not hurt

private:
	GraphManager();
	virtual ~GraphManager();
};

