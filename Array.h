#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
using namespace std;


template <class T, unsigned long long SIZE = 0>
class Array
{
    unsigned long long size;
    T* arr;

    
public:
    class mException { };
    Array(int _size = SIZE)try : size(_size), arr(new T[size]) {}
    catch (bad_alloc& e) { e.what(); throw; }
    Array(const Array& rhs) :arr(new T[rhs.size]), size(rhs.size)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = rhs.arr[i];
        }
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
    T& operator[](int index) throw (mException)
    {
        if (index < 0 || index >= size) throw mException();
        return arr[index];
    }
    const unsigned long long& operator[](const T& item)
    {
        for (auto i = 0; i < size; ++i)
            if (arr[i] == item)
                return i;
        return -1;
    }
    const T& operator[](int index) const throw(mException)
    {
        if (index < 0 || index >= size) throw mException();
        return arr[index];
    }
    const Array operator++(int) //postfix
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
    static class iterator
    {
        const Array* data;
        unsigned long long index;
        friend class Array;
    public:
        iterator(const Array* arr, int size) : data(arr), index(size) { }
        const T& operator*() const
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
    	
        const unsigned long long Index()const { return index; }
    };
    iterator begin() const { return iterator(this, 0); }
    iterator end() const { return iterator(this, size); }
    iterator at(unsigned long long i) const { return iterator(this, i); }
	//const unsigned long long& Index(const char& c)const
 //   {
 //       for (auto i = 0; i < size; ++i)
 //           if (arr[i] == c)
 //               return i;
 //       return -1;
 //   }
};

#endif


