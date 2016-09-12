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
	/*关于User的操作*/
public:
	/*检查用户是否登录*/
	bool IsLogin();
	//根据名称查找工作,参数：工作名称
	Job* FindByName(string name);
	//查找某个分类下的所有工作,参数：工作名称
	Category* FindByCategoryName(string name);
	//添加工作,参数1：工作类,参数2：工作类别名称
	void addJob(Job* job, string categoryName);
public:
	//所有类别及类别下的工作
	void show();
public:
	//登陆,参数1：用户名,参数2：用户密码
	User* Login(string _name, string _password);
};
