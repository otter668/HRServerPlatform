#include "stdafx.h"
#include "DataProvider.h"
DataProvider::DataProvider()
{
	_user = nullptr;
	_userList = new UserList(16);
	_categories = new CategoryList(16);
	/*��ʼ��Category*/
	Category* _cat1 = new Category(1, "����");
	Category* _cat2 = new Category(2, "���");
	Job* _job1 = new Job(1, "����Ա", "��д����", 1500, "���ݿƴ�Ѷ�ɽ����Ƽ����޹�˾", "�������ʦ");
	_cat1->Jobs()->add(*_job1);
	Job* _job2 = new Job(2, "����", "UI���", 1300, "���ݿƴ�Ѷ�ɽ����Ƽ����޹�˾", "����");
	_cat2->Jobs()->add(*_job2);
	_categories->add(*_cat1);
	_categories->add(*_cat2);
}


DataProvider::~DataProvider()
{
	if (nullptr != _user)
	{
		delete _user;
		_user = nullptr;
	}
	if (nullptr != _categories)
	{
		delete _categories;
		_categories = nullptr;
	}
}

/*�û�����*/

bool DataProvider::IsLogin()
{
	return !(_user == nullptr);
}
void DataProvider::show()
{
	_categories->show();
}
Job* DataProvider::FindByName(string name)
{
	for (int i = 0; i < _categories->Count(); ++i)
	{
		Category* cat = _categories->get(i);
		for (int j = 0; j < cat->Jobs()->Count(); ++j)
		{
			Job* job = cat->Jobs()->get(j);
			string jobName = job->getName();
			if (jobName==name)
			{
				return job;
			}
		}
	}
	return nullptr;
}
Category* DataProvider::FindByCategoryName(string name)
{
	for (int i = 0; i < _categories->Count(); ++i)
	{
		Category* cat = _categories->get(i);
		if (cat->getName() == name)
		{
			return cat;
		}
	}
	return nullptr;
}
void DataProvider::addJob(Job* job, string categoryName)
{
	bool flag = false;
	int num = 1;
	for (int i = 0; i < _categories->Count(); ++i)
	{
		Category*  cat = _categories->get(i);
		if (cat->getName()==categoryName)
		{
			cat->Jobs()->add(*job);
			flag = true;
		}
	}
	if (!flag)
	{
		Category* _catnew = new Category(num++, categoryName);
		_categories->add(*_catnew);
		_catnew->Jobs()->add(*job);
	}
}
User* DataProvider::Login(string name, string password)
{
	for (int i = 0; i < _userList->Count(); i++)
	{
		User *tempUser = _userList->get(i);
		if ((tempUser->getName()==name)&& (tempUser->getPassword()==password))
		{
			return tempUser;
		}
	}
	return nullptr;
}