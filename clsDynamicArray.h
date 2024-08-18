#pragma once
#include <iostream>;
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray = nullptr;

public:
	T* OriginalArray;
	
	//parametraized constructor
	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;
		
		_Size = Size;

		OriginalArray = new T[_Size];
	}
	//destructor
	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	void Print()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
	}

	bool SetItem(int index, T item)
	{
		if (index >= _Size || index < 0)
			return false;

		OriginalArray[index] = item;
		return true;
	}
	T GetItem(int index)
	{
		if (index < 0)
			index *= -1; //convert to positive

		return OriginalArray[index];
	}

	int Size()
	{
		return _Size;
	}
	void Resize(int NewSize)
	{
		if (NewSize < 0) 
			NewSize = 0;

		_TempArray = new T[NewSize];

		//change to NewSize if it's less, (to take the needed elements in for loop)
		if (NewSize < _Size) 
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i]; //copy array elements
		}

		//change to NewSize after the loop
		_Size = NewSize;

		delete[] OriginalArray; //free the array elements
		OriginalArray = _TempArray; //TempArray has the needed elements
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Reverse()
	{	
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - i - 1];
		}
		
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		delete[] OriginalArray;
		OriginalArray = new T[0];
		//another solution: Resize(0);
	}

	//find by value, returns the index
	int Find(T DataValue)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == DataValue)
				return i;
		}
		return -1; //means not found
	}

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0) return false;

		_Size--;
		_TempArray = new T[_Size];
		
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index ; i < _Size ; i++)
		{
			_TempArray[i] = OriginalArray[i + 1];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}
	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}
	bool DeleteItem(T DataValue)
	{
		return DeleteItemAt(Find(DataValue));
	}

	bool InsertAt(int index, T Data)
	{
		if (index > _Size || index < 0) return false;

		_Size++;
		_TempArray = new T[_Size];
		
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];	
		}
		
		_TempArray[index] = Data;
		
		for (int i = index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool InsertAtBeginning(T Data)
	{
		return InsertAt(0, Data);
	}
	bool InsertAtEnd(T Data)
	{
		return InsertAt(_Size, Data);
	}
	bool InsertBefore(int index, T Data)
	{
		if (index <= 0)
			return InsertAt(0, Data);
		else
			return InsertAt(index, Data);
	}
	bool InsertAfter(int index, T Data)
	{
		if (index >= _Size)
			return InsertAt(_Size, Data);
		else
			return InsertAt(index + 1, Data);
	}





};

