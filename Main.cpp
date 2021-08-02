/***************************************

	Guy Shaked - 205717952
	Gur shmuelevitz - 207423625
	Main file - Tetris game

***************************************/

#include <iostream>


#include "Array.h"
#include "List.h"
#include "Vertex.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

int main()
{
	Vertex v1(0, nullptr, 1);
	Vertex v2(1, nullptr, 1);
	Vertex v3(2, nullptr, 1);
	Vertex v4(3, nullptr, 1);
	Vertex v5(4, nullptr, 1);
	Vertex v6(5, nullptr, 1);
	Vertex v7(6, nullptr, 1);
	Vertex v8(7, nullptr, 1);
	Vertex v9(8, nullptr, 1);
	Vertex v10(9, nullptr, 1);

	Graph G(10);
	G.AddEdge(v1, v4);
	G.AddEdge(v3, v2);
	G.AddEdge(v2, v5);
	G.AddEdge(v6, v10);
	G.AddEdge(v7, v2);
	G.AddEdge(v8, v3);
	G.AddEdge(v9, v3);
	G.AddEdge(v1, v6);
	G.AddEdge(v10, v7);
	G.AddEdge(v10, v5);
	G.AddEdge(v10, v1);
	G.AddEdge(v10, v2);
	G.AddEdge(v10, v4);
	cout << G;
	
}