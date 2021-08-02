#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "Array.h"
#include "Pair.h"
#include "List.h"
#include "Vertex.h"
using namespace Containers;

typedef unsigned long long ulong;

/// <summary>
///
/// TODO:
///		1. BFS ALGORITEM(Graph, Vertex s, Vertex t)
///		2. inside graph - delete edge
///		3. inside graph - G transpose
///		4.
///
///		commant - ctor
///		
/// </summary>

class Graph
{
	ulong size = 0;
	Array<Pair<Vertex, List<Vertex>>> G;

public:
	Graph(ulong _size = 0) :size(_size) { MakeEmptyGraph(); }
	~Graph() = default;
	void MakeEmptyGraph(ulong n);
	void MakeEmptyGraph();
	void IsAdjacent();
	List<int> GetAdjList(int u);
	void RemoveEdge(int u, int v);
	void ReadGraph();
	void PrintGraph();
	int IsEmpty();
	int AddEdge(int u, int v);
	List<int> Adj(int i);
	
	
};

#endif


