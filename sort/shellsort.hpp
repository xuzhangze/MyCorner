#pragma once

#include "compare.hpp"

template <typename T>
void ShellSort(T *array, int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	int gap = size/3 + 1;
	while(gap)
	{
		for(int i = 0; i < gap; i++)
		{
			for(int j = i+gap; j < size; j++)
			{
				for(int k = j; k >= gap; k--)
					if(Less<T>()(array[k], array[k-1]))
						swap(array[k], array[k-1]);
			}
		}

		if(gap == 1)
			break;
		gap = gap/3 + 1;
	}
}
