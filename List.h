#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
using ulong = unsigned long long;
using namespace std;

template<class T>
class List
{

	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;

		Node(const T& _data = NULL) :data(_data) {}
		Node(const Node& node) : data(node.data), prev(node.prev), next(node.next) {}
		Node& operator=(const Node& node)
		{
			if(this!=&node)
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
		Node& operator*() { return *this; }
		friend ostream& operator<<(ostream& out, const Node& node)
		{
			out << node.data;
			return out;
		}
	};

	class Iterator
	{
		Node* cur = nullptr;
	
	public:
		Iterator() = default;
		Iterator(Node* node) :cur(node) {}
		Iterator(const Iterator& i_Iter) :cur(i_Iter.cur) {}
		Node* GetPtr() { return cur; }
		T& operator*() const
		{
			return cur->data;
		}
		Iterator& operator ++()
		{
			if(cur != nullptr && cur->next != nullptr)
				cur = cur->next;
			return *this;

		}
		Iterator& operator --()
		{
			if(cur != nullptr && cur->prev != nullptr)
				cur = cur->prev;
			return *this;
		}
		Iterator operator ++(int)
		{
			Iterator temp(*this);
			if((cur != nullptr) && (cur->next != nullptr))
				cur = cur->next;
			return temp;
		}
		Iterator operator --(int)
		{
			Iterator temp(*this);
			if((cur != nullptr) && (cur->prev != nullptr))
				cur = cur->prev;
			return temp;
		}
		bool operator == (const Iterator& iter)
		{
			return cur == iter.cur;
		}
		bool operator != (Iterator& iter)
		{
			return !(*this == iter);
		}

		Iterator& operator = (Iterator& iter)
		{
			cur = iter.cur;
			return (*this);
		}
		Iterator& operator = (T& data)
		{
			cur->data = data;
			return (*this);
		}
	};

	void PushFirst(Node* node)
	{
		node->prev = head;
		node->next = tail;
		head->next = node;
		tail->prev = node;
	}

public:
	ulong size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	class mException
	{
	public:
		static void badAloc() {
			std::cout << "Allocation error!";
		}
		static void outOfRange() {
			std::cout << "Out of range error!";
		}
	};
	
	List()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	List(const List& lst) { *this = lst; }
	~List() { this->Clear(); }
	void Clear()
	{
		Node* cur = head;
		for(ulong i=0;i<size;++i)
		{
			cur = cur->next;
			delete cur->prev;
		}
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	
	const Node& operator[](ulong index)const
	{
		return this->operator[](index);
	}
	Node& operator[](ulong index)
	{
		if(index < 0 || index >= size)
		{
			mException::outOfRange();
			throw mException();
		}
		Node* cur = head->next;
		for(ulong i = 0; i < index; ++i)
			cur = cur->next;
		return *cur;
	}
	
	List& operator=(const List& lst)
	{
		if(this!=&lst)
		{
			Clear();
			Node* cur = lst.head->next;
			for(ulong i = 0; i < lst.size; ++i)
			{
				PushBack(cur);
				cur = cur->next;
			}
		}
		return *this;
	}
	void PushBack(const T& data)
	{
		Node* node = new Node(data);
		if(size == 0)
			PushFirst(node);
		else
		{
			node->next = tail;
			node->prev = tail->prev;
			tail->prev->next = node;
			tail->prev = node;
		}
		++size;
	}
	void PushBack(Node* node)
	{
		PushBack(node->data);
	}
	void PushFront(const T& data)
	{
		Node* node = new Node(data);
		if(size == 0)
			PushFirst(node);
		else
		{
			node->prev = head;
			node->next = head->next;
			head->next->prev = node;
			head->next = node;
		}
		++size;
	}
	void PushFront(Node* node)
	{
		if(size == 0)
			PushFirst(node);
		else
		{
			node->prev = head;
			node->next = head->next;
			head->next->prev = node;
			head->next = node;
		}
		++size;
	}

	friend ostream& operator<<(ostream& out, const List& lst)
	{
		Node* cur = lst.head->next;
		out << "[";
		for(ulong i = 0; i < lst.size; ++i)
		{
			out << (*cur);
			cur = cur->next;
			if(i < lst.size - 1)
				out << ", ";
		}
		out << "]" << endl;
		return out;
	}
	T& front()
	{
		return head->next->data;
	}
	T& back()
	{
		return tail->prev->data;
	}
	Iterator begin() const {
		return Iterator(head->next);
	}
	Iterator end() const {
		return Iterator(tail);
	}
	Iterator at(unsigned long long i) const {
		return Iterator((*this)[i]);
	}
};
#endif
