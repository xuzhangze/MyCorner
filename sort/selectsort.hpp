#pragma once

#include "compare.hpp"

template <typename T>
void SelectSort(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	for(int i = 0; i < (int)size-1; i++)
	{
		int sub = i;
		for(int j = i+1; j < (int)size; j++)
			if(Less<T>()(array[j], array[sub]))
				sub = j;
		if(sub != i)
			swap(array[i], array[sub]);
	}
}
