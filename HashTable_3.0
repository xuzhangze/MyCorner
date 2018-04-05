#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


enum State
{
	EMPTY,
	FILLED,
	DELETE
}; 
/*
template <class K> 
struct Elem 
{ 
	K _key; 
	State _state;
	Elem(K key = K())
		: _key(key)
		, _state(EMPTY)
	{}
}; 
*/
template <class K, class V> 
struct HashTableNode 
{ 
	HashTableNode* _pNext; 
	K _key; 
	V _value; 

	HashTableNode() 
		: _pNext(NULL) 
	{} 
	HashTableNode(const K& key, const K& value) 
		: _pNext(NULL) 
		, _key(key) 
		, _value(value) 
	{} 
};


 
 
const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] =
{  
	53ul,         97ul,         193ul,       389ul,       769ul,
	1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
	49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
	1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
	50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
 	1610612741ul, 3221225473ul, 4294967291ul  
};

static size_t BKDRHash(const char *str)
{  
	unsigned int seed = 131; // 31131131313131131313  
	unsigned int hash = 0;  
	while(*str)  
	{  
		hash = hash * seed + (*str++);  
	}  
	return(hash & 0x7FFFFFFF);
}

template <class K>
struct KeyToInt
{
	int operator()(K key)
	{
		return (int)key;
	}
};

template<>
struct KeyToInt<string>
{
	int operator()(string key)
	{
		return BKDRHash(key.c_str());
	}
};

template <class K, class V, bool IsEqual = true>
class HashTable 
{ 
	typedef HashTableNode<K, V> Node; 
	typedef Node* PNode; 

public: 
	HashTable(size_t capacity = 10)
		: _size(0)
		, _capacity(capacity)
	{
		_hashTable.resize(capacity);
	}
	
	bool Insert(const K key, const V value)
	{
		if(IsEqual)
			InertEqual(key, value);
		else
			InertUnique(key, value);
	}

// 重复 
	bool InertEqual(const K& key, const V& value)
	{
		_CheckCapacity();
		size_t sub = _HashFunc(key);
		PNode pTemp = new Node(key, value);
		_FirstInsert(_hashTable[sub], pTemp);
		_size++;
		return true;
	}

// 元素不能重复 
	bool InertUnique(const K& key, const V& value) 
	{
		if(Find(key))
			return false;
		_CheckCapacity();
		size_t sub = _HashFunc(key);
		PNode pTemp = new Node(key, value);
		_FirstInsert(_hashTable[sub], pTemp);
		_size++;
		return true;
	}

	bool DeleteEqual(const K& key)
	{
		if(_size < 1)
			return false;
		size_t sub = _HashFunc(key);
		PNode pCur = _hashTable[sub]->_pNext;
		PNode pPre = &_hashTable[sub];
		bool flag = false;
		while(pCur)
		{
			if(pCur->_key == key)
			{
				pPre->_pNext = pCur->_pNext;
				delete pCur;
				_size--;
				pCur = pPre->_pNext;
				flag = true;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}
		return flag;
	}

	bool DeleteUnique(const K& key)
	{
		if(_size < 1)
			return false;
		size_t sub = _HashFunc(key);
		PNode pCur = _hashTable[sub]._pNext;
		PNode pPre = &_hashTable[sub];
		while(pCur)
		{
			if(pCur->_key == key)
			{
				pPre->_pNext = pCur->_pNext;
				delete pCur;
				_size--;
				return true;
			}
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		return false;
	}
	PNode Find(const K& key)
	{
		size_t sub = _HashFunc(key);
		PNode pCur = _hashTable[sub]._pNext;
		while(pCur && pCur->_key != key)
			pCur = pCur->_pNext;
		return pCur;
	}

	bool Empty()const 
	{ 
		return 0 == _size; 
	} 

	size_t Size()const 
	{ 
		return _size; 
	} 

	void Swap(HashTable& ht)
	{
		if(&ht != this)
		{
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
			_hashTable.swap(ht._hashTable);
		}
	}

// 清空hashTable中的所有元素 
	void FirstDel(PNode pCur)
	{
		while(pCur)
		{
			PNode pTemp = pCur->_pNext;
			delete pCur;
			pCur = pTemp;
		}
	}
	void Clear()
	{
		if(_size < 1)
			return;
		int size = _hashTable.size();
		for(int i = 0; i < size; i++)
		{
			if(_hashTable[i]._pNext)	
				FirstDel(_hashTable[i]._pNext);
		}
		_size = 0;
	}

	~HashTable() 
	{ 
		Clear(); 
	}

	void PrintElem()
	{
		if(_hashTable.size() > 0)
		{
			size_t size = _hashTable.size();
			for(size_t i = 0; i < size; i++)
			{
				PNode pCur = _hashTable[i]._pNext;
				while(pCur)
				{
					cout << "(" << pCur->_key << ", " << pCur->_value << ")" << endl;
					pCur = pCur->_pNext;
				}
			}
		}
	}

private: 
	void _FirstInsert(Node& site, PNode pNewnode)
	{
		PNode ptmp = site._pNext;
		site._pNext = pNewnode;
		pNewnode->_pNext = ptmp;
	}
	size_t _HashFunc(const K& key) 
	{ 
		return KeyToInt<K>()(key) % _hashTable.capacity();
	}

	void _CheckCapacity()
	{
		size_t size = _hashTable.size();
		size_t newcapacity = _capacity;
		for(size_t i = 0; i < _PrimeSize; i++)
		{
			if(_PrimeList[i] > newcapacity)
			{
				newcapacity = _PrimeList[i];
				break;
			}
		}
		HashTable<K, V> ht(newcapacity);
		if(_size == _capacity)
		{
			for(size_t i = 0; i < size; i++)
			{
				PNode pCur = _hashTable[i]._pNext;
				while(pCur)
				{
					if(IsEqual)
						ht.InertEqual(pCur->_key, pCur->_value);
					else
						ht.InertUnique(pCur->_key, pCur->_value);
					pCur = pCur->_pNext;
				}
			}
			Swap(ht);
		}
	}
private:
	vector<Node> _hashTable;
	size_t _size;
	size_t _capacity;
};
