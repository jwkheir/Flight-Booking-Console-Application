#pragma once
#include "LinkedList.h"


template <class T>
class HashTable
{
private:

	// Array is a reference to an array of Linked Lists.
	LinkedList<T> * array;

	// Length is the size of the Hash Table array.
	int length;

	// Returns an array location for a given item key.
	int hash(std::string itemKey);

public:

	// Constructs the empty Hash Table object.
	// Array length is set to 13 by default.
	HashTable(int tableLength);

	// Adds an item to the Hash Table.
	void insertItem(T * newItem);

	// Deletes an Item by key from the Hash Table.
	// Returns true if the operation is successful.
	bool removeItem(std::string itemKey);

	// Returns an item from the Hash Table by key.
	// If the item isn't found, a null pointer is returned.
	T * getItemByKey(std::string itemKey);

	void updateItem(T * currentItem, std::string itemKey);

	// Display the contents of the Hash Table to console window.
	void printTable();

	// Prints a histogram illustrating the Item distribution.
	void printHistogram();

	// Returns the number of locations in the Hash Table.
	int getLength();

	// Returns the number of Items in the Hash Table.
	int getNumberOfItems();

	// De-allocates all memory used for the Hash Table.
	~HashTable();
};

template <class T>
HashTable<T>::HashTable(int tableLength)
{
	if (tableLength <= 0) tableLength = 13;
	array = new LinkedList<T>[tableLength];
	length = tableLength;
}

// Returns an array location for a given item key.
template <class T>
int HashTable<T>::hash(std::string itemKey)
{
	int value = 0;
	for (int i = 0; i < itemKey.length(); i++)
		value += itemKey[i];
	return (value * itemKey.length()) % length;
}

// Adds an item to the Hash Table.
template <class T>
void HashTable<T>::insertItem(T * newItem)
{
	int index = hash(newItem->key);
	array[index].insertItem(newItem);
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
template <class T>
bool HashTable<T>::removeItem(std::string itemKey)
{
	int index = hash(itemKey);
	return array[index].removeItem(itemKey);
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
template <class T>
T * HashTable<T>::getItemByKey(std::string itemKey)
{
	int index = hash(itemKey);
	return array[index].getItem(itemKey);
}

template <class T>
void HashTable<T>::updateItem(T * currentItem, std::string itemKey)
{
	array->updateItem(currentItem, itemKey);
}


// Display the contents of the Hash Table to console window.
template <class T>
void HashTable<T>::printTable()
{
	std::cout << "\n\nHash Table:\n";
	for (int i = 0; i < length; i++)
	{
		std::cout << "Bucket " << i + 1 << ": ";
		array[i].printList();
	}
}

// Prints a histogram illustrating the Item distribution.
template <class T>
void HashTable<T>::printHistogram()
{
	std::cout << "\n\nHash Table Contains ";
	std::cout << getNumberOfItems() << " Items total\n";
	for (int i = 0; i < length; i++)
	{
		std::cout << i + 1 << ":\t";
		for (int j = 0; j < array[i].getLength(); j++)
			std::cout << " X";
		std::cout << "\n";
	}
}

// Returns the number of locations in the Hash Table.
template <class T>
int HashTable<T>::getLength()
{
	return length;
}

// Returns the number of Items in the Hash Table.
template <class T>
int HashTable<T>::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < length; i++)
	{
		itemCount += array[i].getLength();
	}
	return itemCount;
}

// De-allocates all memory used for the Hash Table.
template <class T>
HashTable<T>::~HashTable()
{
	delete[] array;
}