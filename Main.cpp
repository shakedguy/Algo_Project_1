/***************************************

	Guy Shaked - 205717952
	Gur shmuelevitz - 207423625
	Main file - Tetris game

***************************************/

#include <iostream>
#include <stdio.h>

#include "Array.h"
#include "List.h"
#include "Vertex.h"
#include "Graph.h"
#include "Queue.h"
#include "Node.h"

using namespace std;


void ShortestRoutesTree(const Graph& G)
{

	
}

int main()
{	
	Graph G;
	int size;
	cin >> size;
	if(size < 0)
		cout << "Invalid input" << endl;
	else if(size == 0)
		cout << "Empty Graph" << endl;
	else
	{
		G.MakeEmptyGraph(size);
		Vertex s, t, first, second;
		cin >> s.data;
		cin >> t.data;
		while(!cin.eof())
		{
			if(second.data != 0)
			{
				G.AddEdge(first, second);
				first.data = second.data = 0;
			}
			else
			{
				if(first.data == 0)
					cin >> first.data;
				else if(second.data == 0)
					cin >> second.data;
			}
		}
		if(first.data != 0 || second.data != 0)
			cout << "Invalid input" << endl;
		else
			G.BFS(s);
	}
}
