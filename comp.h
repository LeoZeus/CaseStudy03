#pragma once
#include "iostream"
#include "vector"
//#include <cstdint>


using namespace std;

struct ipANDmask
{
	vector<char> block;
};


class COMP
{
private:
	int  name;
	int size;
	vector<ipANDmask> arr;
public:
	void getSize(int size)
	{
		this->size = size;
	}

	void getData(ipANDmask data)
	{
		this->arr.push_back(data);
	}

	bool isConnect(COMP com)
	{
		for (int i = 0; i < this->size; ++i)
			for (int j = 0; j < com.size; ++j)
				if (this->arr[i] == com.arr[j])
					return true;
		return false;
	}
};

struct LIST
{
	int size;
	vector<COMP> comp;
};

