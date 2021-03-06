#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

enum FLAG
{
	EMPTY,
	FILLED,
	DELETE
};

template<class K>
struct HashTableElem
{
	K _key;
	FLAG _flag;
	HashTableElem(K key = K())
		: _key(key)
		, _flag(EMPTY)
	{}
};

 const int _PrimeSize = 28;
 static const unsigned long _PrimeList[_PrimeSize] =
 {      
 	53ul,         97ul,         193ul,       389ul,       769ul,  
 	1543ul,       3079ul,       6151ul,      12289ul,     24593ul,  
 	49157ul,      98317ul,      196613ul,    393241ul,    786433ul,  
 	1572869ul ,   3145739ul,    6291469ul,   12582917ul,  25165843ul,  
 	50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,  
 	1610612741ul, 3221225473ul, 4294967291ul  
 };

template <class K>
struct KeyToInt
{
	size_t operator()(K key)
	{
		return (size_t)key;
	}
};

static size_t BKDRHash(const char * str)
{  
	unsigned int seed = 131; // 31131 1313 13 131 1313 13  
	unsigned int hash = 0;  
	while(*str)  
	{  
  		hash = hash * seed + (*str++);  
	}  
	return (hash & 0x7FFFFFFF); 
}

template <>
struct KeyToInt<string>
{
	size_t operator()(string key)
	{
		return BKDRHash(key.c_str());
	}
};

template<class K, bool IsLine = true> 
class HashTable 
{ 
	typedef HashTableElem<K> Elem;
public: 
	HashTable(size_t capacity = 10)
		: _hashTable(new Elem[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	bool Insert(const K key)
	{
		CheckCapacity();
		if(Find(key) != -1)
			return false;
		size_t addr = HashFunc(key);
		if(_hashTable[addr]._flag != EMPTY)
			LineCheck(addr);	
		_hashTable[addr]._key = key;
		_hashTable[addr]._flag = FILLED;
		_size++;
		return true;
	}
	int Find(const K& key)
	{
		size_t addr = HashFunc(key);
		if(_hashTable[addr]._flag != EMPTY)
		{
			if(_hashTable[addr]._flag == FILLED && _hashTable[addr]._key == key)
				return addr;
			size_t newaddr = addr;
			while(++newaddr != addr)
			{
				if(newaddr >= _capacity)
					newaddr = newaddr%_capacity;
				if(_hashTable[newaddr]._flag == FILLED && _hashTable[newaddr]._key == key)
					return newaddr;
				if(_hashTable[newaddr]._flag == EMPTY)
					break;
			}
			return -1;
		}
		return -1;
	}
	bool Delete(const K& key)
	{
		int addr = Find(key);
		if(addr != -1)
		{
			_hashTable[addr]._flag = DELETE;
			return true;
		}
		return false;
	}
	size_t Size()const 
	{ 
		return _size; 
	} 

	bool Empty()const 
	{ 
		return 0 == _size; 
	} 

	void PrintElem()
	{
		if(_hashTable)
		{
			for(size_t i = 0; i < _capacity; i++)
			{
				if(_hashTable[i]._flag == FILLED)
					cout << "(" << _hashTable[i]._key << "," << i << ")" << endl;
			}
		}
		cout << "size:" << _size << endl << "capacity:" << _capacity << endl;
	}

	~HashTable()
	{
		if(_hashTable)
		{
			delete[] _hashTable;
			_size = 0;
			_capacity = 0;
		}
	}

private: 
	size_t HashFunc(const K& key) 
	{	 
		return KeyToInt<K>()(key) % _capacity;
		//return key % _capacity;
	} 

// 线性探测 
	void LineCheck(size_t& hashAddr)
	{
		while(_hashTable[hashAddr]._flag != EMPTY)
		{
			hashAddr++;
			if(hashAddr >= _capacity)
				hashAddr %= _capacity;
		}
	}

// 二次探测 
	void SecondCheck(size_t hashAddr, size_t i)
	{
		;
	}

	void CheckCapacity()
	{
		if(_size*10/_capacity == 7)
		{
			//增容
			int primeindex = 0;
			for(; primeindex < (int)_PrimeSize; primeindex++)
				if(_PrimeList[primeindex] > _capacity)
					break;
			HashTable<K> ht(_PrimeList[primeindex]);
			for(size_t i = 0; i < _capacity; i++)
			{
				if(_hashTable[i]._flag == FILLED)
					ht.Insert(_hashTable[i]._key);
			}
			Swap(ht);
		}
	}
	void Swap(HashTable& ht)
	{
		if(this != &ht)
		{
			swap(_hashTable, ht._hashTable);
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
		}
	}

private: 
	Elem* _hashTable; 
	size_t _size; 
	size_t _capacity; 
}; 
