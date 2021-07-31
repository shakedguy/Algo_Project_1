#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
#include "List.h"
using namespace std;

typedef unsigned long long ulong;

template <class T, unsigned long long SIZE = 0>
class Array
{
    ulong size;
    T* arr = nullptr;

    class iterator
    {
        const Array* data;
        ulong index;
        friend class Array;
    public:
        iterator(const Array* arr, ulong size) : data(arr), index(size) { }
        T& operator*() const
        {
            return data->arr[index];
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++* this;
            return temp;
        }
        iterator& operator++()
        {
            ++index;
            return *this;
        }
        iterator& operator=(const T& item)
        {
            data->arr[index] = item;
            return *this;
        }
        friend bool operator==(const iterator& rhs, const iterator& lhs)
        {
            return !(rhs.index != lhs.index);
        }
        friend bool operator!=(const iterator& rhs, const iterator& lhs)
        {
            return !(rhs.index == lhs.index);
        }
    };
    void swap(T& t1, T& t2)
    {
	    T tmp(t1);
    	t1 = t2;
    	t2 = tmp;
    }
public:
    class mException
    {
    public:
        static void badAloc() { std::cout << "Allocation error!"; }
        static void outOfRange() { std::cout << "Out of range error!"; }
    };
    Array(const T& initialize = 0)try : size(SIZE), arr(new T[size])
    {
        for (int i = 0; i < size; ++i)
            arr[i] = initialize;
    }
    catch (mException& e) { e.badAloc(); throw; }
    Array(const Array& rhs) :arr(new T[rhs.size]), size(rhs.size)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = rhs.arr[i];
        }
    }
    Array(T rhs[]) : size(SIZE), arr(new T[size])
    {
      for(int i = 0; i < size; ++i)
          arr[i] = rhs[i];
    }
    Array(const List<T>& lst) :size(SIZE), arr(new T[size])
    {
      *this = lst;
    }
    Array& operator=(T rhs[])
    {
        for (int i = 0; i < size; ++i)
            arr[i] = rhs[i];
        return *this;
    }
    Array& operator=(const List<T>& lst)
    {
      auto cur = lst.head->next;
      for(int i = 0; i < size; ++i)
      {
	      arr[i] = cur->data;
        cur = cur->next;
      }
      return *this;
    }
    Array& operator=(const Array& rhs)
    {
        if (this == &rhs)
            return *this;

        delete[] arr;
        size = rhs.size;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rhs.arr[i];
        }
        return *this;
    }
    T& operator[](int index)
    {
        if (index < 0 || index >= size) throw mException();
        return arr[index];
    }
    const unsigned long long& at(const T& item)
    {
        for (auto i = 0; i < size; ++i)
            if (arr[i] == item)
                return i;
        return -1;
    }
    const T& operator[](int index) const
    {
        if (index < 0 || index >= size) throw mException();
        return arr[index];
    }
    Array operator++(int) //postfix
    {
        Array temp = *this;
        ++* this;
        return temp;
    }
    Array& operator++()
    {
        for (int i = 0; i < size; ++i)
            ++arr[i];
        return *this;
    }
    const Array& operator+=(long long add)
    {
        for (int i = 0; i < size; i++)
            arr[i] += add;
        return *this;
    }
    const Array& operator-=(long long sub) { return *this += (-sub); }
    friend ostream& operator<<(ostream& out, const Array& rhs)
    {
        out << "[";
        for (int i = 0; i < rhs.size; i++)
        {
            out << rhs.arr[i];
            if (i < rhs.size - 1)
                out << ", ";
        }
        out << "]" << endl;
        return out;
    }
    friend istream& operator>>(istream& in, Array& rhs)
    {
        cout << "enter " << rhs.size << " digits to fill the array" << endl;
        for (int i = 0; i < rhs.size; i++) in >> rhs.arr[i];
        return in;
    }

    ~Array()
    {
        delete[] arr;
    }
    bool empty() const
    {
        return size == 0;
    }
    T front()
    {
        return arr[0];
    }
    T back()
    {
        return arr[size - 1];
    }

    iterator begin() const { return iterator(this, 0); }
    iterator end() const { return iterator(this, size); }
    iterator at(unsigned long long i) const { return iterator(this, i); }
	

};

#endif


