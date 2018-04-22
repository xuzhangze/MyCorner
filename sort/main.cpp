//#include "insertsort.hpp"
//#include "binaryinsert.hpp"
//#include "shellsort.hpp"
//#include "selectsort.hpp"
//#include "heapsort.hpp"
//#include "bubblesort.hpp"
//#include "quicksort.hpp"
//#include "mergersort.hpp"
#include "compare.hpp"
//#include "countsort.h"
#include "LSDSort.h"

/*
void test1()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)
	{
		arr[i] = rand() % 100;
	}
	for(int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl << "sort:" << endl;
	InsertSort(arr, sz);
	for(int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void test2()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	BinaryInsert(arr, sz);
	for(int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "insert sort error! " << i << endl;
	}
}

void test3()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	ShellSort(arr, sz);
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "insert sort error! " << i << endl;
	}
}
void test4()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	SelectSort(arr, sz);
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "insert sort error! " << i << endl;
	}
}
void test5()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	HeapSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << i << endl;
	}
}
void test6()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	BubbleSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << i << endl;
	}
}

void test7()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	QuickSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << arr[i] << endl;
	}
}

void test8()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	MergerSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << arr[i] << endl;
	}
}
void test9()
{
	int arr[100] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	CountSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << arr[i] << endl;
	}
}
*/
void test10()
{
	int arr[200] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(0));
	for(int i = 0; i < sz; i++)    //Assign values with random numbers
	{
		arr[i] = rand() % sz;
	}
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl << endl << endl << "sort:" << endl;
	LSDSort(arr, sz);             //sort
	for(int i = 0; i < sz; i++)    //print array
		cout << arr[i] << " ";
	cout << endl;
	for(int i = 1; i < sz; i++)  //check that the sort is correct
	{
		if(Less<int>()(arr[i], arr[i-1]))
			cout << "sort error! " << arr[i] << endl;
	}
}
int main()
{
	test10();

	return 0;
}
