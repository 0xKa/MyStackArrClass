//queue based on dynamic array
#pragma once
#include <iostream>
#include "clsDynamicArray.h";
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray <T> _DynamicArray;

public:
	void Print()
	{
		_DynamicArray.Print();
	}

	bool IsEmpty()
	{
		return _DynamicArray.IsEmpty();
	}

	void push(T data)
	{
		_DynamicArray.InsertAtEnd(data);
	}
	void pop()
	{
		_DynamicArray.DeleteFirstItem();
	}

	int Size()
	{
		return _DynamicArray.Size();
	}

	T front()
	{
		return _DynamicArray.GetItem(0);
	}
	T back()
	{
		return _DynamicArray.GetItem(Size() - 1);
	}

	T GetItem(int index)
	{
		return _DynamicArray.GetItem(index);
	}

	void Reverse()
	{
		_DynamicArray.Reverse();
	}

	void UpdateItem(int index, T NewValue)
	{
		_DynamicArray.InsertAt(index, NewValue);
	}

	void InsertAfter(int index, T NewValue)
	{
		_DynamicArray.InsertAfter(index, NewValue);
	}
	void InsertAtFront(T NewValue)
	{
		_DynamicArray.InsertAtBeginning(NewValue);
	}
	void InsertAtBack(T NewValue)
	{
		_DynamicArray.InsertAtEnd(NewValue); //another solution: *this.push(Value);
	}

	void Clear()
	{
		_DynamicArray.Clear();
	}

};