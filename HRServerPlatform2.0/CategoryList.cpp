#include "stdafx.h"
#include "CategoryList.h"

CategoryList::CategoryList(int initialSize)
{
	this->_count = 0;
	this->_capacity = initialSize;
	this->_data = new Category[initialSize];
}

CategoryList::~CategoryList()
{
	if (nullptr != _data)
	{
		delete[] _data;
	}
}

void CategoryList::resize()
{
	_capacity *= 2;
	Category* temp = new Category[_capacity];
	memcpy(temp, _data, _count);
	delete[] _data;
	_data = temp;
}

void CategoryList::add(Category& category)
{
	if (_count == _capacity)
	{
		resize();
	}
	_data[_count++] = category;
}

Category* CategoryList::get(int index)
{
	return (&_data[index]);
}

void CategoryList::show()
{
	for (int i = 0; i < _count; ++i)
	{
		_data[i].show();
		cout << "\n";
		cout << "\n";
	}
}

int CategoryList::Count()
{
	return _count;
}