#pragma once
#include "iostream"
#include "vector"

using namespace std;

struct ipANDmask
{
	vector<char> block;
};

struct LIST
{
	int size;
	vector<COMP> comp;
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
};
