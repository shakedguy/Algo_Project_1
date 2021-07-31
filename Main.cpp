/***************************************

	Guy Shaked - 205717952
	Gur shmuelevitz - 207423625
	Main file - Tetris game

***************************************/
#include <iostream>
#include "Array.h"
#include "List.h"
using namespace std;

int main()
{
	
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.PushBack(5);
	Array<int, 5> arr = lst;
	cout << arr;
}