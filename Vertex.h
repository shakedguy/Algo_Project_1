#ifndef _VERTEX_H_
#define _VERTEX_H_

typedef unsigned long long ulong;
#include <iostream>
using namespace std;

struct Vertex
{
	ulong data;
	Vertex* parent = nullptr;
	ulong length = 0;

	Vertex(ulong _data = 0, Vertex* v = nullptr, ulong _len = 0) :
		data(_data), parent(v), length(_len) {}
	bool operator==(Vertex v)const
	{
		return (data == v.data);
	}
	Vertex& operator=(const Vertex& v)
	{
		if(this != &v)
		{
			data = v.data;
			parent = v.parent;
			length = v.length;
		}
		return *this;
	}
	bool operator==(const Vertex& v)
	{
		return (data == v.data && parent == v.parent && length == v.length);
	}
	bool operator!=(const Vertex& v) { return (!operator==(v)); }
	friend ostream& operator<<(ostream& out, const Vertex& v)
	{
		out << v.data;
		return out;
	}
};

#endif


