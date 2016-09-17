#pragma once
#include "stdafx.h"
/*
 用户
 */
class User
{
public:
	virtual int getsalary()=0;//计算工资
private:
	string _name;//用户名
	string _password;//密码
public:
	string getName();//获取用户名
	string getPassword();//获取密码
public:
	User();
	User(string, string);
	~User();
};