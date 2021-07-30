#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
typedef unsigned long long ulong;
using namespace std;

template<class T>
class List
{

	template<class G>
	class Node
	{
		G data;
		Node* next = nullptr;
		Node* prev = nullptr;
		
	};

	Node<T>* head;
	Node<T>* tail;
	ulong length = 0;
public:
	
};

#endif


