#pragma once
#include "User.h"
class UserList
{
private:
	User* _data;//用户
	int _count;//集合长度
	int _capacity;//集合最大长度
public:
	UserList(int);
	UserList();
	~UserList();
public:
	//获取集合长度
	int Count();
public:
	//添加用户，参数：用户类
	void add(User& _user);
	//获取用户
	User* get(int i);
public:
	//登陆,参数1：用户名,参数2：用户密码
	bool Login(string _name, string _password);
private:
	//扩充集合容量
	void resize();
};

