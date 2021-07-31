#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include "Node.h";

using ulong = unsigned long long;
using namespace std;

namespace Containers
{
	template<class T>
	class List
	{

		class Iterator
		{
			Node<T>* cur = nullptr;
			friend class List<T>;

		public:
			Iterator() = default;
			Iterator(Node<T>* node) :cur(node) {}
			Iterator(const Iterator& i_Iter) :cur(i_Iter.cur) {}
			Node<T>* GetPtr() {
				return cur;
			}
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

		void PushFirst(Node<T>* node)
		{
			node->prev = head;
			node->next = tail;
			head->next = node;
			tail->prev = node;
		}

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

	public:

		ulong size = 0;
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;

		List()
		{
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
			tail->prev = head;
		}
		List(const List& lst) {
			*this = lst;
		}
		~List() {
			this->Clear();
		}
		void Clear()
		{
			Node<T>* cur = head;
			for(ulong i = 0; i < size; ++i)
			{
				cur = cur->next;
				delete cur->prev;
			}
			head = new Node<T>();
			tail = new Node<T>();
			head->next = tail;
			tail->prev = head;
			size = 0;
		}

		const Node<T>& operator[](ulong index)const
		{
			return this->operator[](index);
		}
		Node<T>& operator[](ulong index)
		{
			if(index < 0 || index >= size)
			{
				mException::outOfRange();
				throw mException();
			}
			Node<T>* cur = head->next;
			for(ulong i = 0; i < index; ++i)
				cur = cur->next;
			return *cur;
		}

		List& operator=(const List& lst)
		{
			if(this != &lst)
			{
				Clear();
				Node<T>* cur = lst.head->next;
				for(ulong i = 0; i < lst.size; ++i)
				{
					PushBack(cur);
					cur = cur->next;
				}
			}
			return *this;
		}
		void assign(ulong count, const T& value)
		{
			for(ulong i = 0; i < count; ++i)
				PushBack(value);
		}

		void assign(ulong count, Node<T>* node)
		{
			for(ulong i = 0; i < count; ++i)
				PushBack(node);
		}
		
		void PushBack(const T& data)
		{
			Node<T>* node = new Node<T>(data);
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
		void PushBack(Node<T>* node)
		{
			PushBack(node->data);
		}
		void PushFront(const T& data)
		{
			Node<T>* node = new Node<T>(data);
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
		void PushFront(Node<T>* node)
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
			Node<T>* cur = lst.head->next;
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

		bool Empty()const
		{
			return (size == 0);
		}

		Iterator begin() const {
			return Iterator(head->next);
		}
		Iterator end() const {
			return Iterator(tail);
		}
		Iterator at(ulong i) const {
			return Iterator((*this)[i]);
		}
	};
	
}

#endif
