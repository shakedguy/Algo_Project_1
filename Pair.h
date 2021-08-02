#ifndef _PAIR_H_
#define _PAIR_H_
#include <iostream>
#include "Vertex.h"
#include "List.h"


template<typename T, typename G>
class Pair
{
	
public:
	T first;
	G second;

	Pair(T _first = NULL, G _second = NULL) : first(_first), second(_second) {}

	
};

#endif


