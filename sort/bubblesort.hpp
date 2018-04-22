#include "compare.hpp"

template <typename T>
void BubbleSort(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	for(int i = 0; i < (int)size-1; i++)
	{
		for(int j = size-1; j > i; j--)
		{
			if(Less<int>()(array[j], array[j-1]))
				swap(array[j], array[j-1]);
		}
	}
}
