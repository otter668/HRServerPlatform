#pragma once
#include "User.h"
class UserList
{
private:
	User* _data;//�û�
	int _count;//���ϳ���
	int _capacity;//������󳤶�
public:
	UserList(int);
	UserList();
	~UserList();
public:
	//��ȡ���ϳ���
	int Count();
public:
	//����û����������û���
	void add(User& _user);
	//��ȡ�û�
	User* get(int i);
public:
	//��½,����1���û���,����2���û�����
	bool Login(string _name, string _password);
private:
	//���伯������
	void resize();
};

