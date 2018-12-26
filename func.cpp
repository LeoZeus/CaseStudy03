#include "lib.h"
#include "comp.h"
#include <vector>
#include <map>

uint32_t convertBinary(ipANDmask x)
{
	uint32_t n = 0;

	for (int i = 0; i < 3; ++i)
		n = (n | x.block[i]) << 8;
	n = n | x.block[3];

	return n;

}

int32_t handle1(string buffer)
{
	ipANDmask tmp;
	int count = 0;
	string temp;
	for (int i = 0; i < buffer.length(); ++i)
	{
		if (buffer[i] != '.')
			temp += buffer[i];
		else
		{
			tmp.block[count] = atoi(temp.c_str());
			count++;
			temp.clear();
		}
	}
	return convertBinary(tmp);
}

int32_t handle(string buffer)
{
	int index = buffer.find(' ');
	int32_t ip = handle1(string(buffer, index));
	int32_t mask = handle1(string(buffer, index + 1, buffer.length()));
	int32_t ret;
	ret = ip & mask;
	return ret;
}

void readFile(string input_string, LIST* &list, int &start, int &end)
{
	ifstream input;
	input.open(input_string);

	string buffer;
	int num;
	input >> buffer;
	list->size = num = atoi(buffer.c_str());

	for (int i = 0; i < list->size; ++i)
	{
		input >> buffer;
		num = atoi(buffer.c_str());
		list->comp.resize(i + 1);
		list->comp[i].setSize(num);
		for (int j = 0; j < num; ++j)
		{
			input >> buffer;
			list->comp[i].setData(handle(buffer));
		}
	}

	getline(input, buffer, ' ');
	start = atoi(buffer.c_str());
	input >> buffer;
	end = atoi(buffer.c_str());

	input.close();
}

void writeFile(string output_string, vector<int> loc, vector<int> distance, int start, int end)
{
	ofstream output;
	output.open(output_string);

	vector<int> kq;

	if (distance[end] = INT_MAX) {
		output << "Khong" << "\n";
	}
	else output << "Co" << "\n";

	int i = end;
	while (start[i] != -1)
	{
		kq.push_front(start[i]);
		i = start[i];
	}


	output.close();
}

void builtGraph(vector<vector <int>> graph, LIST *ls)
{
	for (int i = 0; i < graph.size(); ++i)
		for (int j = 0; i < graph.size(); ++j)
			if (ls->comp[i].isConnect(ls->comp[j]))
				graph[i][j] = 1;
}

// Dijkstra
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