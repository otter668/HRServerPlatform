#include "stdafx.h"
#include "User.h"
User::User(string name, string password)
{
	_name = name;
	_password = password;
}
User::User()
{
	//cout << "Log:User constructor!" << endl;
	_name;
	_password;
}
string User::getName()
{
	return this->_name;
}
string User::getPassword()
{
	return this->_password;
}
User::~User()
{
}