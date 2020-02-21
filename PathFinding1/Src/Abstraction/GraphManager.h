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
// 64 nodes in the graph 
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
public:
	static GraphManager& instance();

	GraphManager(GraphManager const&) = delete;
	void operator=(GraphManager const&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
		//       C++ book, that deleted functions should generally
		//       be public as it results in better error messages
		//       due to the compilers behavior to check accessibility
		//       before deleted status
		//       this probably wont matter here but dose not hurt


	// 64 nodes, 0 based
	const char *name[64] =
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


	cost weights[126] =
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
	const char* getNodeNames();

private:
	GraphManager();
	virtual ~GraphManager();

};

