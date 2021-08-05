
#include "Graph.h"

#include <fstream>


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
		G[i].first.data = i + 1;
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
	if(Exist(u) && Exist(v) && (!(*this)[u].IsPresent(v)))
	{
		(*this)[u].PushBack(v);
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

void Graph::ReadGraph(std::string fileName)
{
	fstream file;
	file.open(fileName, ios_base::in);
	if(!file.is_open() || file.eof())
		throw;
	char c;
	file >> size;
	G.Resize(size);
	MakeEmptyGraph(size);
	Vertex s, t, u, v;
	file >> s.data;
	file >> t.data;
	while(!file.eof())
	{
		if(u.data != 0 && v.data != 0)
		{
			AddEdge(u, v);
			u.data = v.data = 0;
		}
		else if(u.data == 0)
			file >> u.data;
		else if(v.data == 0)
			file >> v.data;
	}
	file.close();
}


void Graph::BFS(Vertex s)
{
	// Mark all the vertices as not visited
	bool* visited = new bool[size];
	for(ulong i = 0; i < size; ++i)
		visited[i] = false;
	//Vertex& u = s;
	// Create a queue for BFS
	Queue<Vertex> queue;
	// Mark the current node as visited and enqueue it
	visited[s.data] = true;
	queue.enQueue(s);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	
	ulong level = 0;
	
	while(!queue.Empty())
	{

		// Dequeue a vertex from queue and print it
		s = queue.Front().data;
		cout << s << " -> level " << s.length << endl;
		queue.deQueue();

		List<Vertex>& u_adj = Adj(s);
		++level;
		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (Vertex& v : u_adj)
		{
			v.length = level;
			G[v.data - 1].first.length = level;
			if(!visited[v.data])
			{
				visited[v.data] = true;
				queue.enQueue(v);
			}
		}
	}
}







