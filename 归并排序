#include "compare.hpp"

template <typename T>
static void _conflation(T *array, const int left, const int mid, const int right)
{
	assert(NULL != array && left >= 0 && mid >= 0 && right >= 0);
	if(right - left < 2)
		return;
	T *parr = new T[right-left];
	int i = left;
	int j = mid;
	int index = 0;
	while(i < mid && j < right)
	{
		if(Less<T>()(array[i], array[j]))
			parr[index++] = array[i++];
		else
			parr[index++] = array[j++];
	}
	while(i < mid)
		parr[index++] = array[i++];
	while(j < right)
		parr[index++] = array[j++];
	for(int i = 0; i < right-left; i++)
		array[left+i] = parr[i];

	delete[] parr;
}
template <typename T>
static void _mergerSort(T *array, const int left, const int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	if(right - left <= 1)
		return;
	const int mid = left + ((right - left) >> 1);
	_mergerSort(array, left, mid);
	_mergerSort(array, mid, right);
	_conflation(array, left, mid, right);
}

template <typename T>
void MergerSort(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	_mergerSort(array, 0, size);
}
