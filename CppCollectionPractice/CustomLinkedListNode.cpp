#include "CustomLinkedListNode.h"

CustomLinkedListNode::CustomLinkedListNode()
{
}

CustomLinkedListNode::CustomLinkedListNode(DataContainer dataContainer)
{
	data = dataContainer;
	next = nullptr;
}

CustomLinkedListNode::~CustomLinkedListNode()
{
	next = nullptr;
}
