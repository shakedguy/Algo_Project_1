
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

bool Graph::IsAdjacent(const Vertex& u, const Vertex& v)
{
	for (auto& element : G)
	{
		if(element.first == u)
			return element.second.IsPresent(v);
	}
	return false;
}

int Graph::AddEdge(Vertex u, Vertex v)
{
	bool flag1, flag2;
	flag1 = flag2 = false;
	for(auto& element : G)
	{
		if(element.first == u)
		{
			if(!element.second.IsPresent(v))
			{
				element.second.PushBack(v);
				flag1 = true;
			}
		}
		else if(element.first == v)
		{
			if(!element.second.IsPresent(u))
			{
				element.second.PushBack(u);
				flag2 = true;
			}
		}
	}
	return (flag1 && flag2) ? 1 : 0;
}




