#include <iostream>
#include "CustomVector.h"
#include "CustomLinkedList.h"

void PrintCollectionElements(Collection &collection)
{
	std::cout << "========================" << std::endl;
	for (int i = 0; i < collection.GetSize(); i++)
	{
		std::cout << collection.GetElementAt(i).GetValue() << std::endl;
	}
	std::cout << "========================" << std::endl;
}

void TestInserts(Collection &customCollection)
{
	DataContainer data(69);
	try
	{
		customCollection.InsertAt(25, data);
	}
	catch (int error)
	{
		std::cout << error << std::endl;
	}

	customCollection.PushToEnd(data);
	PrintCollectionElements(customCollection);
	customCollection.PushToStart(data);
	PrintCollectionElements(customCollection);
	customCollection.InsertAt(15, data);
	PrintCollectionElements(customCollection);
}

void TestRemovals(Collection &customCollection)
{
	try
	{
		customCollection.Remove(35);
	}
	catch (int error)
	{
		std::cout << error << std::endl;
	}

	customCollection.RemoveFromEnd();
	PrintCollectionElements(customCollection);
	customCollection.RemoveFromStart();
	PrintCollectionElements(customCollection);
	customCollection.Remove(12);
	PrintCollectionElements(customCollection);
}

void TestBubbleSort(Collection &customCollection)
{
	std::cout << "Sorting test:" << std::endl;
	customCollection.BubbleSort();
	PrintCollectionElements(customCollection);
}

int main()
{
	CustomLinkedList linkedList;
	for (int i = 0; i < 20; ++i)
	{
		DataContainer data(i);
		linkedList.PushToEnd(data);
	}

	TestInserts(linkedList);
	TestRemovals(linkedList);
	TestBubbleSort(linkedList);

	//CustomVector customVector;
	//for (int i = 0; i < 20; ++i)
	//{
	//	DataContainer data(i);
	//	customVector.PushToEnd(data);
	//}

	//TestInserts(customVector);
	//TestRemovals(customVector);
	//TestBubbleSort(customVector);
	//std::cout << "Size of our vector: " << customVector.GetSize() << std::endl;
	system("pause");
	return 0;
}
