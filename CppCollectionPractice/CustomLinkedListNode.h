#pragma once
#include "DataContainer.h"
#include "CustomLinkedListNode.h"

class CustomLinkedListNode
{
public:
	CustomLinkedListNode();
	CustomLinkedListNode(DataContainer data);
	~CustomLinkedListNode();

	DataContainer data;
	CustomLinkedListNode* next;
};
