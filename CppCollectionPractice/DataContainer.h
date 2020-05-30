#pragma once

class DataContainer
{
private:
	int dataValue;
public:
	DataContainer(int value);
	DataContainer();
	~DataContainer();
	int GetValue();
	void SetValue(int value);
};