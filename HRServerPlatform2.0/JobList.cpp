#include "stdafx.h"
#include "JobList.h"

JobList::JobList(int initialSize)
{
	this->_count = 0;
	this->_capacity = initialSize;
	this->_data = new Job[initialSize];
}


JobList::~JobList()
{
	if (nullptr != _data)
	{
		delete[] _data;
		_data = nullptr;
	}
}

void JobList::resize()
{
	_capacity *= 2;
	Job* temp = new Job[_capacity];
	memcpy(temp, _data, _count);
	delete[] _data;
}

void JobList::add(Job& job)
{
	if (_count == _capacity)
	{
		resize();
	}
	_data[_count++] = job;
}

Job* JobList::get(int index)
{
	return (&_data[index]);
}
void JobList::show()
{
	cout << "\n";
	for (int i = 0; i < _count; ++i)
	{
		_data[i].show();
	}
}

int JobList::Count()
{
	return _count;
}