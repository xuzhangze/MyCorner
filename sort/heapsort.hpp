#include "compare.hpp"

template <typename T>
void Adjust(T *array, int parent, int size)
{
	assert(NULL != array && parent >= 0);
	int child = 2*parent + 1;
	while(child < size)
	{
		if(child+1 < size)
			child = Greater<int>()(array[child], array[child+1]) ? child : child+1;
		if(Greater<T>()(array[child], array[parent]))
			swap(array[parent], array[child]);
		else
			break;
		parent = child;
		child = 2*parent + 1;
	}
}

template <typename T>
void HeapSort(T *array, int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	for(int i = ((size-2)>>1); i >= 0; i--)
		Adjust(array, i, size);
	while(size > 1)
	{
		swap(array[0], array[size-1]);
		size--;
		Adjust(array, 0, size);
	}
}
