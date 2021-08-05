#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

using namespace std;

//namespace Containers
//{

	template<typename T=int>
	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;

		Node(const T& _data = NULL) :data(_data) {}
		Node(const Node& node) : data(node.data), prev(node.prev), next(node.next) {}
		Node& operator=(const Node& node)
		{
			if(this != &node)
			{
				data = node.data;
				prev = node.prev;
				next = node.next;
			}
			return *this;
		}
		Node& operator=(const T& node)
		{
			this->data = node;
			return *this;
		}
		Node operator++(int) //postfix
		{
			Node temp = *this;
			++this->data;
			return temp;
		}
		Node& operator++()
		{
			++this->data;
			return *this;
		}
		const Node& operator+=(long long add)
		{
			this->data += add;
			return *this;
		}
		const Node& operator-=(long long sub) {
			return (*this) += (-sub);
		}
		Node& operator*() {
			return *this;
		}
		bool operator==(const Node& node)
		{
			return (data == node.data && prev == node.prev && next == node.next);
		}
		bool operator==(const Node* node) { return (this->operator==(*node)); }
		bool operator!=(const Node* node) { return (!this->operator==(*node)); }
		bool operator!=(const Node& node) { return (!operator==(node)); }

		friend ostream& operator<<(ostream& out, const Node& node)
		{
			out << node.data;
			return out;
		}
	};
//}
#endif


