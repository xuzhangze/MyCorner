#include "compare.hpp"

template <typename T>
void SelectMid(T *array, int left, int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	if(right - left <= 1)
		return;
	int mid = left + ((right-left)>>1);

	int buf[3] = { left, mid, right-1 };
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2-i; j++)
		{
			if(Greater<T>()(array[buf[j]], array[buf[j+1]]))
				swap(buf[j], buf[j+1]);
		}
	}
	if(array[buf[1]] != array[right-1])
		swap(array[buf[1]], array[right-1]);
}

template <typename T>
int Partition1(T *array, int left, int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	assert(right - left > 1);
	int start = left;
	int tail = right-1;
	T key = array[right-1];
	while(start < tail)
	{
		while((Less<T>()(array[start], key)||array[start]==key) && start < tail)
			start++;
		while((Greater<T>()(array[tail], key)||array[tail]==key) && start < tail)
			tail--;
		if(start < tail)
			swap(array[start], array[tail]);
	}
	if(start != right-1)
		swap(array[start], array[right-1]);
	return start;
}
template <typename T>
int Partition2(T *array, int left, int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	assert(right - left > 1);
	int start = left;
	int tail = right-1;
	T key = array[right-1];
	while(start < tail)
	{
		while((Less<T>()(array[start], key)||array[start]==key) && start < tail)
			start++;
		if(Greater<T>()(array[start], key))
			array[tail] = array[start];
		while((Greater<T>()(array[tail], key)||array[tail]==key) && start < tail)
			tail--;
		if(Less<T>()(array[tail], key))
			array[start] = array[tail];
	}
	if(start < right)
		array[start] = key;
	return start;
}
template <typename T>
int Partition3(T *array, int left, int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	assert(right - left > 1);
	int start = left-1;
	int tail = left;
	T& key = array[right-1];
	while(tail < right-1)
	{
		start++;
		tail++;
		while(Less<T>()(array[start], key) && tail < right-1)
		{
			start++;
			tail++;
		}
		while(Greater<T>()(array[tail], key) && tail < right-1)
			tail++;
		if(tail < right && Greater<T>()(array[start], array[tail]))
			swap(array[start], array[tail]);
	}
	return start;
}
template <typename T>
void _quickSort(T *array, int left, int right)
{
	assert(NULL != array && left >= 0 && right >= 0);
	if(right - left <= 1)
		return;
	SelectMid(array, left, right);
	int keysub = Partition3(array, left, right);
	_quickSort(array, left, keysub);
	_quickSort(array, keysub+1, right);
}

template <typename T>
void QuickSort(T *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	_quickSort(array, 0, (int)size);
}
