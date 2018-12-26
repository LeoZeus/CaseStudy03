#include "lib.h"
#include "comp.h"
#include "func.cpp"


int main()
{
	LIST* list;

	int start, end;
	readFile("input.txt", list, start, end);

	vector<vector<int>> graph;
	builtGraph(graph, list);

	auto result = dijkstra(graph, start);
	writeFile("output.txt", result.second, result.first, start, end);

	system("pause");
	return 0;
}

