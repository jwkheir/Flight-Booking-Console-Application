#pragma once
/*
* Author: Guy Walker
* Updated: 27/05/16
*/
template <class T>
class Stack
{
public:
	int maxSize;
	T* stackData;
	int top;
public:

	Stack(int maxSize)
	{
		stackData = new T[(int)maxSize];
		top = -1;
	}

	void Push(T value)
	{
		top++;
		stackData[top] = value;
	}

	T Pop()
	{
		return stackData[top--];
	}

	T Peek()
	{
		return stackData[top];
	}

	bool IsEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if (top == (maxSize - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

