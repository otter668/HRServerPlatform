#pragma once
#include "User.h"
#include "CategoryList.h"
#include "JobList.h"
#include "UserList.h"
class DataProvider
{
private:
	User *_user;
	UserList* _userList;
	CategoryList *_categories;
public:
	DataProvider();
	~DataProvider();
	/*����User�Ĳ���*/
public:
	/*����û��Ƿ��¼*/
	bool IsLogin();
	//�������Ʋ��ҹ���,��������������
	Job* FindByName(string name);
	//����ĳ�������µ����й���,��������������
	Category* FindByCategoryName(string name);
	//��ӹ���,����1��������,����2�������������
	void addJob(Job* job, string categoryName);
public:
	//�����������µĹ���
	void show();
public:
	//��½,����1���û���,����2���û�����
	User* Login(string _name, string _password);
};
