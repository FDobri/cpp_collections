#include <iostream>
#include "CustomVector.h"

#pragma region Setup

CustomVector::CustomVector()
{
	allocatedSize = INITIAL_ARRAY_SIZE;
	vectorArray = (DataContainer*)malloc(allocatedSize * sizeof(DataContainer));
	size = 0;
}

CustomVector::CustomVector(int desiredSize)
{
	vectorArray = (DataContainer*)malloc(desiredSize * sizeof(DataContainer));
	size = 0;
	allocatedSize = desiredSize;
}

CustomVector::~CustomVector()
{
	if (allocatedSize != 0)
	{
		free(vectorArray);
	}
	vectorArray = nullptr;
}

#pragma endregion

#pragma region Inserts

void CustomVector::_PushToEnd(const DataContainer& value)
{
	_AllocateAndInsert(size, value);
}

void CustomVector::_PushToStart(const DataContainer& value)
{
	_AllocateAndInsert(0, value);
}

void CustomVector::_InsertAt(int index, const DataContainer& value)
{
	_AllocateAndInsert(index, value);
}

#pragma endregion

#pragma region Removes

void CustomVector::_RemoveFromEnd()
{
	_AllocateAndRemove(size - 1);
}

void CustomVector::_RemoveFromStart()
{
	_AllocateAndRemove(0);
}


void CustomVector::_Remove(int index)
{
	_AllocateAndRemove(index);
}

#pragma endregion

#pragma region Misc

int CustomVector::GetSize()
{
	return size;
}

DataContainer CustomVector::_GetElementAt(int index)
{
	return vectorArray[index];
}

void CustomVector::_SetElement(int index, DataContainer data)
{
	vectorArray[index] = data;
}

void CustomVector::_SwapElements(int index1, int index2)
{
	DataContainer temp = vectorArray[index2];
	vectorArray[index2] = vectorArray[index1];
	vectorArray[index1] = temp;
}

#pragma endregion

#pragma region Private

void CustomVector::_AllocateAndInsert(int index, DataContainer elementToInsert)
{
	++size;
	int requiredAllocatedSize = _GetRequiredAllocatedSize(size);
	if (requiredAllocatedSize != allocatedSize)
	{
		allocatedSize = requiredAllocatedSize;
		DataContainer* temp = (DataContainer*)malloc(allocatedSize * sizeof(DataContainer));
		for (int i = 0; i < index; i++)
		{
			temp[i] = vectorArray[i];
		}
		temp[index] = elementToInsert;
		for (int i = index; i < size - 1; i++)
		{
			temp[i + 1] = vectorArray[i];
		}
		free(vectorArray);
		vectorArray = temp;
		temp = nullptr;
	}
	else
	{
		if (index == size)
		{
			vectorArray[index] = elementToInsert;
		}
		else
		{
			for (int i = size - 1; i > index; --i)
			{
				vectorArray[i] = vectorArray[i - 1];
			}
			vectorArray[index] = elementToInsert;
		}
	}
}

void CustomVector::_AllocateAndRemove(int index)
{
	int requiredAllocatedSize = _GetRequiredAllocatedSize(size);
	if (allocatedSize == requiredAllocatedSize)
	{
		for (int i = index; i < size - 1; ++i)
		{
			vectorArray[i] = vectorArray[i + 1];
		}
	}
	else
	{
		//realloc could be very useful here
		DataContainer* temp = (DataContainer*)malloc((allocatedSize * sizeof(DataContainer)));
		for (int i = 0; i < index; i++)
		{
			temp[i] = vectorArray[i];
		}
		for (int i = index; i < size - 1; ++i)
		{
			temp[i] = vectorArray[i + 1];
		}
	}
	--size;
}

int CustomVector::_GetRequiredAllocatedSize(int size)
{
	int tempSize = 2;
	while (tempSize < size)
	{
		tempSize *= 2;
	}

	return tempSize;
}

#pragma endregion