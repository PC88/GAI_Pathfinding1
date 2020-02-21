#pragma once
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

