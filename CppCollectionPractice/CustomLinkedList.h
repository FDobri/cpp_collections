#pragma once
#include "Collection.h"
#include "CustomLinkedListNode.h"

class CustomLinkedList : public Collection
{
public:
	CustomLinkedList();
	~CustomLinkedList();

	CustomLinkedListNode* head;
	CustomLinkedListNode* tail;

	int GetSize() override;

private:
	int size;
	DataContainer _GetElementAt(int index) override;
	void _SetElement(int index, DataContainer data) override;
	void _SwapElements(int index1, int index2) override;

	void _InsertAt(int index, const DataContainer& data) override;
	void _PushToEnd(const DataContainer& data) override;
	void _PushToStart(const DataContainer& data) override;

	void _Remove(int index) override;
	void _RemoveFromEnd() override;
	void _RemoveFromStart() override;

	bool _IndexLoopConditionMet(int count, int index);
	bool _LoopEndConditionMet(CustomLinkedListNode* node);
};
