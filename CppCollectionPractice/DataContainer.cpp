#include "DataContainer.h"
#include <iostream>

DataContainer::DataContainer(int x)
{
	dataValue = x;
}

DataContainer::DataContainer()
{
	dataValue = 0;
}

DataContainer::~DataContainer()
{
}

int DataContainer::GetValue()
{
	return dataValue;
}

void DataContainer::SetValue(int x)
{
	dataValue = x;
}