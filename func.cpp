#include "lib.h"
#include "comp.h"


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

void writeFile(string output_string)
{
	ofstream output;
	output.open(output_string);



	output.close();
}
