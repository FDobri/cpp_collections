#pragma once
#include "Collection.h"

class CustomVector : public Collection
{
public:
	CustomVector();
	CustomVector(int allocatedSize);
	~CustomVector();

	int GetSize() override;

private:
	const int INITIAL_ARRAY_SIZE = 8;
	DataContainer* vectorArray;
	int allocatedSize;
	int size;

	void _AllocateAndInsert(int index, DataContainer elementToInsert);
	void _AllocateAndRemove(int index);
	int _GetRequiredAllocatedSize(int size);

	DataContainer _GetElementAt(int index) override;
	void _SetElement(int index, DataContainer data) override;
	void _SwapElements(int index1, int index2) override;

	void _InsertAt(int index, const DataContainer& data) override;
	void _PushToEnd(const DataContainer& data) override;
	void _PushToStart(const DataContainer& data) override;

	void _Remove(int index) override;
	void _RemoveFromEnd() override;
	void _RemoveFromStart() override;
};