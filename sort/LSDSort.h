#include <vector>

int Pow(const int& left, const int& right)
{
	if(right <= 0)
		return 1;
	int product = 1;
	for(int i = 0; i < (int)right; i++)
		product *= left;
	return product;
}

void LSDSort(int *array, const int size)
{
	assert(NULL != array && size > 0);
	if(size == 1)
		return;
	
	int place = 0;
	for(int i = 0; i < (int)size; i++)
	{
		int num = array[i];
		int status = 0;
		while(num)
		{
			status++;
			num /= 10;
		}
		if(status > place)
			place = status;
	}

	for(int i = 0; i < place; i++)
	{
		vector< vector<int> > bucket;
		bucket.resize(10);
		for(int j = 0; j < (int)size; j++)
			bucket[(array[j]/Pow(10,i))%10].push_back(array[j]);
		int index = 0;
		for(int j = 0; j < 10; j++)
		{
			int vsize = bucket[j].size();
			for(int k = 0; k < vsize; k++)
				array[index++] = bucket[j][k];
		}
	}
}
