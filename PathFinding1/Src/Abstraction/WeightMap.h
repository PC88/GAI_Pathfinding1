#pragma once
#include <ostream>


using namespace boost;
using namespace std;

template <class WeightMap>
class time_writer
{
public:
	time_writer(WeightMap w) : wm(w) {}
	template <class Edge>
	void operator()(ostream &out, const Edge& e) const {
		out << "[label=\"" << wm[e] << "\", fontsize=\"11\"]";
	}
private:
	WeightMap wm;
};