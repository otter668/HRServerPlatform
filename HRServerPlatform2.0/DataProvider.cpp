#include "stdafx.h"
#include "DataProvider.h"
DataProvider::DataProvider()
{
	_user = nullptr;
	_userList = new UserList(16);
	_categories = new CategoryList(16);
	/*初始化Category*/
	Category* _cat1 = new Category(1, "开发");
	Category* _cat2 = new Category(2, "设计");
	Job* _job1 = new Job(1, "程序员", "编写代码", 1500, "苏州科大讯飞教育科技有限公司", "软件工程师");
	_cat1->Jobs()->add(*_job1);
	Job* _job2 = new Job(2, "美工", "UI设计", 1300, "苏州科大讯飞教育科技有限公司", "美工");
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

/*用户操作*/

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