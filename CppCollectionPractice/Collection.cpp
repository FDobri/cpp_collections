#include "Collection.h"

DataContainer Collection::GetElementAt(int index)
{
	_GetElementCheck(index);
	return _GetElementAt(index);
}

void Collection::SetElement(int index, DataContainer dc)
{
	_GetElementCheck(index);
	_SetElement(index, dc);
}

void Collection::SwapElements(int index1, int index2)
{
	_GetElementCheck(index1);
	_GetElementCheck(index2);
	_SwapElements(index1, index2);
}

void Collection::InsertAt(int index, const DataContainer & data)
{
	_InsertionCheck(index);
	_InsertAt(index, data);
}

void Collection::BubbleSort()
{
	int arraySize = GetSize();
	for (int i = 0; i < arraySize - 1; ++i)
	{
		for (int j = i; j < arraySize - i - 1; ++j)
		{
			if (GetElementAt(j).GetValue() > GetElementAt(j + 1).GetValue())
			{
				_SwapElements(j, j + 1);
			}
		}
	}
}

void Collection::PushToEnd(const DataContainer & data)
{
	_InsertionCheck(GetSize());
	_PushToEnd(data);
}

void Collection::PushToStart(const DataContainer & data)
{
	_InsertionCheck(0);
	_PushToStart(data);
}

void Collection::Remove(int index)
{
	_RemovalCheck(index);
	_Remove(index);
}

void Collection::RemoveFromEnd()
{
	_RemovalCheck(GetSize() - 1);
	_RemoveFromEnd();
}

void Collection::RemoveFromStart()
{
	_RemovalCheck(0);
	_RemoveFromStart();
}

Collection::~Collection()
{
}

void Collection::_GetElementCheck(int index)
{
	if (index < 0 || index >(GetSize() - 1))
	{
		throw - 1;
	}
}

void Collection::_InsertionCheck(int index)
{
	if (index < 0 || index >(GetSize()))
	{
		throw - 1;
	}
}

void Collection::_RemovalCheck(int index)
{
	if (index < 0 || index >(GetSize() - 1)) // moze se napravit u jedan bool check da se smanji dupliciranje koda (line 75)
	{
		throw - 1;
	}
	else if (GetSize() == 0)
	{
		throw - 1;
	}
}
