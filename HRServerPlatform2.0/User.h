#pragma once
#include "stdafx.h"
/*
 �û�
 */
class User
{
public:
	virtual int getsalary()=0;//���㹤��
private:
	string _name;//�û���
	string _password;//����
public:
	string getName();//��ȡ�û���
	string getPassword();//��ȡ����
public:
	User();
	User(string, string);
	~User();
};