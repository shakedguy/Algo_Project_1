#ifndef _VERTEX_H_
#define _VERTEX_H_

typedef unsigned long long ulong;

struct Vertex
{
	ulong data;
	Vertex* parent;
	ulong length;
};

#endif


