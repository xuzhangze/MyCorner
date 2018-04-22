#pragma once

#include "compare.hpp"
template <typename T>
static int BinaryFind(T *array, T key, int left, int right)
{
	assert(NULL != array);
	assert(left >= 0 && right >= 0 && left < right);
	if(right - left == 1 && Less<T>()(key, array[left]))
		return left;
	while(left < right)
	{
		int mid = left + ((right-left)>>1);
		if((mid == left && Less<T>()(key, array[mid]))
		|| (Less<T>()(key, array[mid]) && Less<T>()(array[mid-1], key)))
			return mid;
		else if(Less<T>()(key, array[mid]))
			right = mid;
		else
			left = mid+1;
	}
	return right;
}

template <typename T>
void BinaryInsert(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	for(int i = 1; i < (int)size; i++)
	{
		T temp = array[i];
		int place = BinaryFind(array, temp, 0, i);
		if(place < i)
		{
			for(int j = i; j > place; j--)
				array[j] = array[j-1];				
			array[place] = temp;
		}
	}
}
