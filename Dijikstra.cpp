#include <vector>
#include <map>

using std::vector;
 std::pair<vector<int>, vector<int>> dijkstra(std::vector<std::vector<int> > graph, int src) {
	int n = graph.size();
	vector<bool> mark(n, false);
	vector<int> distance(n, INT_MAX);
	vector<int> start(n, -1);
	distance[src] = 0;
	int u = 0;
	int j = 0;
	int minDis = 0;
	for (int count = 1; count < n; ++count) {
		for (j = 0, minDis = INT_MAX; j < n; ++j) {
			if (!mark[j] && distance[j] < minDis) {
				minDis = distance[j];
				u = j;
			}
		}
	
		mark[u] = true;
		for (j = 0; j < n; ++j) {
			if (distance[u] + graph[u][j] < distance[j]) {
				distance[j] = distance[u] + graph[u][j];
				start[j] = u;
			}
		}
	}

	return std::make_pair(distance, start);
}

 int main() {
	 std::vector< std::vector<int>> gr = {
		 {0, 2, 3, 6},
		 {2, 0, 2, 2},
		 {3, 2, 0, 5},
		 {6, 2, 5, 0}
	 };
	 std::pair<vector<int>, vector<int>> result = dijkstra(gr, 0);
	 return 0;
 }