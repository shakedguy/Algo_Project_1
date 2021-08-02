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
	int IsEmpty() { return (size) ? 1 : 0; }
	int AddEdge(Vertex u, Vertex v)const;
	friend ostream& operator<<(ostream& out, const Graph& v)
	{
		for (auto& item : v.G)
		{
			out << "[" << item.first << "] -> " << item.second;
		}
		out << endl;
		return out;
	}
	List<Vertex>& operator[](const Vertex& u)const;
	bool Exist(const Vertex& u)const;
	List<Vertex> Adj(Vertex i) { return (*this)[i]; }
	
	
};

#endif


