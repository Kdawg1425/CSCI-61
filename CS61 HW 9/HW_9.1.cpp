#include <iostream>
#include "graph.h"
using namespace std;

int main() {
	main_savitch_15::graph<int> a;
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	//cout << a.size() << endl;
	a.add_edge(0, 1);
	a.add_edge(0, 2);
	a.add_edge(0, 3);
	a.add_edge(1, 2);
	a.add_edge(2, 3);
	a.longestDis(0,3);
	return 0;
}
