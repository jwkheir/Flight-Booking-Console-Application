#include "stdafx.h"
#include "PriorityQueue.h"


/*
* Author: Guy Walker
* Updated: 27/05/16
*/
PriorityQueue::PriorityQueue(int size) :size(size){
	data = new int[size];
	count = 0;
}


PriorityQueue::~PriorityQueue(){
}


// Exercise 4
void PriorityQueue::Insert(int item){
	// Queue is empty
	if (count == 0){
		data[count++] = item;
	}
	else {
		int j;
		// Start at the end work backwards 
		for (j = (count - 1); j >= 0; j--){
			// If the new item is larger than current
			if (item > data[j]){
				// Shift the current up
				data[j + 1] = data[j];
			}
			else {
				// Finished shifting
				break;
			}
		}
		data[j + 1] = item;
		count++;
	}
}

int PriorityQueue::Remove(){
	return data[--count];
}

int PriorityQueue::PeakMin(){
	return data[count - 1];
}

bool PriorityQueue::IsEmpty(){
	return count == 0;
}


bool PriorityQueue::IsFull(){
	return count == size;
}


int PriorityQueue::Size(){
	return size;
}