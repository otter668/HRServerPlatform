#include "stdafx.h"
#include "UserList.h"
#include "AdminUser.h"

UserList::UserList(int initialSize)
{
	this->_count = 0;
	this->_capacity = initialSize;
	this->_data = new AdminUser[initialSize];
	User *user = new AdminUser("HR", "123");
	this->_data[_count++] = *user;
}

UserList::~UserList()
{
	if (nullptr != _data)
	{
		delete[] _data;
	}
}
int UserList::Count()
{
	return _count;
}
void UserList::resize()
{
	_capacity *= 2;
	User* temp = new AdminUser[_capacity];
	memcpy(temp, _data, _count);
	delete[] _data;
	_data = temp;
}
void UserList::add(User& _user)
{
	if (_count == _capacity)
	{
		resize();
	}
	_data[_count++] = _user;
}
User* UserList::get(int i)
{
	return &_data[i];
}