#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <iostream>
#include "Node.h"
using namespace std;
typedef unsigned long long ulong;

template<typename T>
struct Queue
{
	typedef Node<T> Node;
	
	Node* front;
	Node* back;
	ulong size = 0;
	
	Queue() :front(nullptr), back(nullptr) {}
	Queue(const Queue& q) :front(q.front), back(q.back), size(q.size) {}
	const Node& Front() { return *front; }
	const Node& Back() { return *back; }
	void enQueue(T data)
	{
		Node* node = new Node(data);

		if(back != nullptr)
		{
			back->next = node;
			back = node;
		}
		else
			front = back = node;
		++size;
	}

	void deQueue()
	{
		if(front != nullptr)
		{
			Node* node = front;
			front = front->next;

			if(front == nullptr)
				back = nullptr;

			delete (node);
			--size;
		}
	}

	Queue& operator=(const Queue& q)
	{
		if(this != &q)
		{
			front = q.front;
			back = q.back;
			size = q.size;
		}
		return *this;
	}
	bool Empty()const { return (size == 0); }
	
	friend ostream& operator<<(ostream& out, const Queue& q)
	{
		out << "<- [";
		Node* cur = q.front;
		while(cur != nullptr)
		{
			if(cur != q.back)
				out << (*cur) << ", ";
			else
				out << (*cur) << "]";
			cur = cur->next;
		}
		return out;
	}
};
#endif


