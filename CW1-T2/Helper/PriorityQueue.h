#pragma once
/*
* Author: Guy Walker
* Updated: 27/05/16
*/
class PriorityQueue{
	int size;
	int *data;
	int count;
public:
	PriorityQueue(int size);
	~PriorityQueue();
	void Insert(int item);
	int Remove();
	int PeakMin();
	bool IsEmpty();
	bool IsFull();
	int Size();
};
