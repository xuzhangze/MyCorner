#pragma once

int FindMax(int *array, const int size)
{
	assert(NULL != array && size > 0);
	int max = array[0];
	for(int i = 1; i < (int)size; i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	return max;
}
int FindMin(int *array, const int size)
{
	assert(NULL != array && size > 0);
	int min = array[0];
	for(int i = 1; i < (int)size; i++)
	{
		if(array[i] < min)
			min = array[i];
	}
	return min;
}
void CountSort(int *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	int max = FindMax(array, size);
	int min = FindMin(array, size);
	int *parr = new int[max-min+1]();
	for(int i = 0; i < (int)size; i++)
		parr[array[i]-min]++;
	int index = 0;
	for(int i = 0; i < max-min+1; i++)
		if(parr[i] > 0)
			for(int j = 0; j < parr[i]; j++)
				array[index++] = min+i;
	delete[] parr;
}
