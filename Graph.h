#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "Array.h"
#include "Pair.h"
#include "List.h"
#include "Vertex.h"
//using namespace Containers;

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
	Graph(const ulong& _size = 0) :size(_size),G(_size) { MakeEmptyGraph(); }
	~Graph() = default;
	void MakeEmptyGraph(ulong n);
	void MakeEmptyGraph();
	bool IsAdjacent(const Vertex& u, const Vertex& v);
	//List<int> GetAdjList(int u){}
	//void RemoveEdge(int u, int v){}
	//void ReadGraph(){}
	//void PrintGraph(){}
	//int IsEmpty(){}
	int AddEdge(Vertex u, Vertex v);
	friend ostream& operator<<(ostream& out, const Graph& v)
	{
		for (auto& element : v.G)
		{
			out << "[" << element.first << "] -> " << element.second;
		}
		return out;
	}
	//List<int> Adj(int i){}
	
	
};

#endif


