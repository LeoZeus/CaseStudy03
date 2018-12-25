#include "lib.h"
#include "comp.h"


ipANDmask handle1(string buffer)
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
	return tmp;
}

ipANDmask handle(string buffer)
{
	int index = buffer.find(' ');
	ipANDmask ip = handle1(string(buffer, index));
	ipANDmask mask = handle1(string(buffer, index + 1, buffer.length()));
	ipANDmask ret;
	for (int i = 0; i < 4; ++i)
	{
		ret.block[i] = ip.block[i] & mask.block[i];
	}
	return ret;
}

void readFile(string input_string, LIST* &list, int start, int end)
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
		list->comp[i].getSize(num);
		for (int j = 0; j < num; ++j)
		{
			input >> buffer;
			list->comp[i].getData(handle(buffer));
		}
	}

	getline(input, buffer, ' ');
	start = atoi(buffer.c_str());
	input >> buffer;
	end = atoi(buffer.c_str());

	input.close();
}

void writeFile(string output_string)
{
	ofstream output;
	output.open(output_string);



	output.close();
}


void builtGraph(vector<vector <int>> graph, LIST *ls)
{
	for (int i = 0; i < graph.size(); ++i)
		for (int j = 0; i < graph.size(); ++j)
			if (ls->comp[i].isConnect(ls->comp[j]))
				graph[i][j] = 1;
}