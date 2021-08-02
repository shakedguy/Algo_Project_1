
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

int Graph::AddEdge(Vertex u, Vertex v)const
{
	bool flag = false;
	if((this->Exist(v) && this->Exist(u)) && 
		(!(*this)[u].IsPresent(v)) && !(*this)[v].IsPresent(u))
	{
		(*this)[u].PushBack(v);
		(*this)[v].PushBack(u);
		flag = true;
	}
	return (flag) ? 1 : 0;

}

List<Vertex>& Graph::operator[](const Vertex& u)const
{
	for (auto& item : G)
	{
		if(item.first == u)
			return item.second;
	}
}

bool Graph::Exist(const Vertex& u)const
{
	for(auto& item : G)
	{
		if(item.first == u)
			return true;
	}
	return false;
}







