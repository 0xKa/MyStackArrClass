// stack based on dynamic array, inherts from queue
#pragma once
#include <iostream>
#include "clsMyQueueArr.h";
using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr <T>
{

public:

	void push(T data)
	{
		clsMyQueueArr <T> ::_DynamicArray.InsertAtBeginning(data);
	}

	T Top()
	{
		return clsMyQueueArr <T> ::_DynamicArray.GetItem(0);
	}
	T Bottom()
	{
		return clsMyQueueArr <T> ::_DynamicArray.GetItem(clsMyQueueArr <T> ::Size() - 1);
	}

	void InsertAtTop(T NewValue)
	{
		clsMyQueueArr <T> ::_DynamicArray.InsertAtBeginning(NewValue);
	}
	void InsertAtBottom(T NewValue)
	{
		clsMyQueueArr <T> ::_DynamicArray.InsertAtEnd(NewValue);
	}

};

