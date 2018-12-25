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
};