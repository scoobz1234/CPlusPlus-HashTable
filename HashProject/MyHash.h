#pragma once
#include <iostream>
#include <stdlib.h>
#include "Item.h"

using namespace std;

#define DEFAULT_HASH_SIZE 40

template <class K, class D>
class MyHash
{
private:

	int hashSize;
	Item<K,D>** HashTable;
	K defaultKey;
	D defaultData;

	int NumberOfItemsInIndex(int index);
	int Hash(K key);

public:

	MyHash(K, D, int = DEFAULT_HASH_SIZE);

	void PrintHash();
	void PrintItemsInIndex(int index);
	void AddItem(K key, D data);
	void FindData(K key);
	void RemoveItem(K key);
};