#pragma once


//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************
template <class T>
class LinkedList
{
private:
	// Head is a reference to a list of data nodes.
	T * head;

	// Length is the number of data nodes.
	int length;

public:
	// Constructs the empty linked list object.
	// Creates the head node and sets length to zero.
	LinkedList();

	// Inserts an item at the end of the list.
	void insertItem(T * newItem);

	// Removes an item from the list by item key.
	// Returns true if the operation is successful.
	bool removeItem(std::string itemKey);

	// Searches for an item by its key.
	// Returns a reference to first match.
	// Returns a NULL pointer if no match is found.
	T * getItem(std::string itemKey);

	void updateItem(T * updateitem, std::string itemKey);

	// Displays list contents to the console window.
	void printList();

	// Returns the length of the list.
	int getLength();

	// De-allocates list memory when the program terminates.
	~LinkedList();
};

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
template <class T>
LinkedList<T>::LinkedList()
{
	head = new T();
	head->next = NULL;
	length = 0;
}

// Inserts an item at the end of the list.
template <class T>
void LinkedList<T>::insertItem(T * newItem)
{
	if (!head->next)
	{
		head->next = newItem;
		length++;
		return;
	}
	T * p = head;
	T * q = head;
	while (q)
	{
		p = q;
		q = p->next;
	}
	p->next = newItem;
	newItem->next = NULL;
	length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
template <class T>
bool LinkedList<T>::removeItem(std::string itemKey)
{
	if (!head->next) return false;
	T * p = head;
	T * q = head;
	while (q)
	{
		if (q->key == itemKey)
		{
			p->next = q->next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p->next;
	}
	return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
template <class T>
T * LinkedList<T>::getItem(std::string itemKey)
{
	T * p = head;
	T * q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (p->key == itemKey))
			return p;
		q = p->next;
	}
	return NULL;
}
template <class T>
void LinkedList<T>::updateItem(T * updateItem, std::string itemKey)
{
	T * p = head;
	T * q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (p->key == itemKey))
		{
			p = updateItem;
			return;
		}
		q = p->next;
	}
}

// Displays list contents to the console window.
template <class T>
void LinkedList<T>::printList()
{
	if (length == 0)
	{
		std::cout << "\n{ }\n";
		return;
	}
	T * p = head;
	T * q = head;
	std::cout << "\n{ ";
	while (q)
	{
		p = q;
		if (p != head)
		{
			std::cout << p->key;
			if (p->next) std::cout << ", ";
			else std::cout << " ";
		}
		q = p->next;
	}
	std::cout << "}\n";
}

// Returns the length of the list.
template <class T>
int LinkedList<T>::getLength()
{
	return length;
}

// De-allocates list memory when the program terminates.
template <class T>
LinkedList<T>::~LinkedList()
{
	/*T * p = head;
	T * q = head;
	while (q)
	{
		p = q;
		q = p->next;
		if (q) delete p;
	}*/
}