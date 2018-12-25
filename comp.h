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
	vector<int32_t> arr;
public:
	void setSize(int size)
	{
		this->size = size;
	}

	void setData(int32_t data)
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

