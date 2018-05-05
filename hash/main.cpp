//#include "hashtable.hpp"
#include "HashTable.hpp"
/*
void test()
{
	int quantity = 15;
	HashTable<int> ht;
	srand((unsigned)time(NULL));
	for(int i = 0; i < quantity; i++)
	{
		int number = rand()%(quantity*5);
		ht.Insert(number);
		cout << number << " ";
	}
	ht.Insert(1);
	ht.Insert(3);
	ht.Insert(5);
	ht.Insert(6);
	ht.Insert(8);
	ht.Insert(2);
	ht.PrintElem();
}
void test1()
{
	HashTable<string> ht;
	ht.Insert("老大");
	ht.Insert("宋二");
	ht.Insert("张三");
	ht.Insert("李四");
	ht.Insert("王五");
	ht.Insert("赵六");
	cout << ht.Find("李四") << endl;
	cout << ht.Find("张四") << endl;
	ht.PrintElem();
}
*/
void test2()
{
	int quantity = 15;
	HashTable<int, int> ht;
	srand((unsigned)time(NULL));
	for(int i = 0; i < quantity; i++)
	{
		int number = rand()%(quantity*5);
		ht.Insert(number, i);
		cout << number << " ";
	}

	ht.PrintElem();
}

int main()
{
	test2();

	return 0;
}
