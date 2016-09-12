#pragma once
#include "DataProvider.h"
#include "CategoryList.h"
class SystemUI
{
private:
	DataProvider* _dataProvider;
private:
	void LoginOperation();//登陆操作
	bool exitSystem();// 退出系统
	void findJob();//根据名称找工作
	void addJob();//添加工作
	void findCategory();//根据分类名称查找
	void showAllJobs();//展示所有工作
public:
	SystemUI();
	~SystemUI();
	/*菜单操作*/
public:
	void showHomeMenuOperation();//主菜单操作
	void showLoginMeunOperation();//登陆菜单操作
	int showHomeMenu();//展示主菜单
	int showLoginMeun();//展示登陆菜单
	void CalculateSalary(int);//计算工资
};


