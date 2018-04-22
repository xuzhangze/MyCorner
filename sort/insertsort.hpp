#pragma once

#include "compare.hpp"


template <typename T>
void InsertSort(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	for(int i = 1; i < (int)size; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(Less<T>()(array[j], array[j-1]))
				swap(array[j], array[j-1]);
		}
	}
}
