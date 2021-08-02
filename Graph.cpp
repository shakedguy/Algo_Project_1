#include "Graph.h"


void Graph::MakeEmptyGraph(ulong n)
{
	G.Resize(n);
	size = n;
	MakeEmptyGraph();
}

void Graph::MakeEmptyGraph()
{
	for(ulong i = 0; i < size; ++i)
	{
		G[i].first.data = i;
	}
}


