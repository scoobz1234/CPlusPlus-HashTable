#include "MyHash.h"

/// <summary>
/// Default constructor for the HashTable...
/// </summary>
/// <param name="defaultKeyEntry"></param>
/// <param name="defaultDataEntry"></param>
/// <param name="size"></param>
template <class K, class D> 
MyHash<K, D>::MyHash(K defaultKeyEntry, D defaultDataEntry, int size)
{

	defaultData = defaultDataEntry;
	defaultKey = defaultKeyEntry;

	hashSize = size;
	HashTable = new Item<K,D> * [size]();

	for (int i = 0; i < hashSize; i++)
	{
		Item<K,D>* n = new Item<K,D>();
		HashTable[i] = n;
		HashTable[i]->key = defaultKey;
		HashTable[i]->data = defaultData;
	}
}

/// <summary>
/// Hash function, probably the most important...
/// This is how we convert the Key to an int
/// manipulate the key so its unique as possible...
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
template <class K, class D> 
int MyHash<K,D>::Hash(K key) {

	int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) 
	{
		hash += (int)key[i];
	}

	index = hash % hashSize;

	return index;
}


/// <summary>
/// this function is used to add a key and data pair to the hash table...
/// checks if the item at index is the placeholder, and replaces it
/// else it iterates the linked list to the end and adds the item.
/// </summary>
/// <param name="key"></param>
/// <param name="data"></param>
template <class K, class D> 
void MyHash<K,D>::AddItem(K key, D data)
{
	int index = Hash(key);

	if (HashTable[index]->key == defaultKey) 
	{
		HashTable[index]->key = key;
		HashTable[index]->data = data;
	}
	else
	{
		Item<K,D>* currItem = HashTable[index];
		Item<K,D>* newItem = new Item<K,D>();
		newItem->key = key;
		newItem->data = data;
		newItem->next = NULL;
		while (currItem->next != NULL) {
			currItem = currItem->next;
		}
		currItem->next = newItem;
	}
}

/// <summary>
/// Prints the hash table...
/// </summary>
template <class K, class D> 
void MyHash<K,D>::PrintHash() 
{
	int number;
	for (int i = 0; i < hashSize; i++) 
	{
		number = NumberOfItemsInIndex(i);
		cout << "-----------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->key << endl;
		cout << HashTable[i]->data << endl;
		cout << "# of items = " << number << endl;
		cout << "-----------------------\n";
	}
}

/// <summary>
/// Prints all items in HashTable index...
/// </summary>
/// <param name="index"></param>
template <class K, class D> 
void MyHash<K,D>::PrintItemsInIndex(int index)
{

	Item<K,D>* listItem = HashTable[index];

	if (listItem == NULL) {
		cout << "index = " << index << " is empty" << endl;
	}
	else {
		cout << "index " << index << " contains the following items\n";
		while (listItem != NULL) {
			cout << "------------------\n";
			cout << listItem->key << endl;
			cout << listItem->data << endl;
			cout << "------------------\n";

			listItem = listItem->next;
		}
	}
}

/// <summary>
/// Function finds data connected to key
/// If key exists returns data paired with key...
/// </summary>
/// <param name="key"></param>
template <class K, class D> 
void MyHash<K,D>::FindData(K key)
{
	int index = Hash(key);
	bool isFound = false;
	D data;

	Item<K,D>* item = HashTable[index];
	while (item != NULL) {
		if (item->key == key) {
			isFound = true;
			data = item->data;
		}
		item = item->next;
	}

	isFound == true ? cout << key << "'s Phone number is : " << data << endl : 
		cout << key << " was not found in table.";
}

/// <summary>
/// Removes an item from the hash table...
/// 4 cases, buckets empty, one item and matches, mult items and first matches
/// mult items and first does not match.
/// </summary>
/// <param name="key"></param>
template <class K, class D> 
void MyHash<K,D>::RemoveItem(K key)
{
	int index = Hash(key);
	Item<K,D>* itemToDelete;
	Item<K,D>* nextItem;
	Item<K,D>* previousItem;

	// if bucket is empty
	if (HashTable[index]->key == defaultKey && HashTable[index]->data == defaultData) {
		cout << key << " not found in the table\n";
	}
	// only one item in the bucket and it matches...
	else if (HashTable[index]->key == key && HashTable[index]->next == NULL) {
		HashTable[index]->key = defaultKey;
		HashTable[index]->data = defaultData;
		cout << key << " Deleted from table" << endl;
	}
	// Match found, first item is matched, but there are other items...
	else if (HashTable[index]->key == key) {
		itemToDelete = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete itemToDelete;
		cout << key << " Removed from the table" << endl;
	}
	// Match found in bucket but first item is not the matched item...
	else {
		nextItem = HashTable[index]->next;
		previousItem = HashTable[index];

		while (nextItem != NULL && nextItem->key != key) {
			previousItem = nextItem;
			nextItem = nextItem->next;
		}
		// No Match
		if (nextItem == NULL) {
			cout << key << " Not found in the table" << endl;
		}
		// match found
		else {
			itemToDelete = nextItem;
			nextItem = nextItem->next;
			previousItem->next = nextItem;
			delete itemToDelete;
			cout << key << " removed from table" << endl;
		}
	}
}


/// <summary>
/// Returns number of items that are in the specified index...
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
template <class K, class D> 
int MyHash<K,D>::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index] == NULL)
	{
		return count;
	}
	else 
	{
		count++;
		Item<K,D>* item = HashTable[index];
		while (item->next != NULL) {
			count++;
			item = item->next;
		}
	}

	return count;
}
