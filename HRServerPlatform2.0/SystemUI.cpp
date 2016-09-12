#include "stdafx.h"
#include "SystemUI.h"
#include "Category.h"
#include "Job.h"
#include "UserList.h"
#include "ProgrammerUser.h"
#include "ArtistUser.h"
SystemUI::SystemUI()
{
	_dataProvider = new DataProvider();
}

SystemUI::~SystemUI()
{
	if (nullptr != _dataProvider)
	{
		delete _dataProvider;
	}
}

int SystemUI::showHomeMenu()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "1.查看工作详情(按工作名称搜索)" << endl;
	cout << "2.添加工作" << endl;
	cout << "3.查看分类详情(按分类名称搜索)" << endl;
	cout << "4.查看所有工作" << endl;
	cout << "5.计算工资" << endl;
	cout << "6.退出" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "请选择：";
	int selection = 0;
	cin.clear();
	cin.sync();
	cin >> selection;
	return selection;
}
void SystemUI::CalculateSalary(int choice)
{
	ProgrammerUser* _user1 = new ProgrammerUser();
	ArtistUser* _user2 = new ArtistUser();
	switch (choice)
	{
	case 1:
		cout << "程序员的工资为:" << _user1->getsalary();
		cout << "\n";
		break;
	case 2:
		cout << "美工的工资为:" << _user2->getsalary();
		cout << "\n";
		break;
	default:
		cout << "不存在该工作类别";
		cout << "\n";
		break;
	}
}
int SystemUI::showLoginMeun()
{
	cout << "-------------------------" << endl;
	cout << "1.登陆" << endl;
	cout << "2.退出" << endl;
	cout << "-------------------------" << endl;
	cout << "请选择：" << endl;
	int selection = 0;
	cin >> selection;
	return selection;
}
void SystemUI::showHomeMenuOperation()
{
	int choice = SystemUI::showHomeMenu();
	int job_choice = 1;
	bool flag = true;
	while (flag)
	{
		switch (choice)
		{
		case 1:
			this->findJob();
			flag = false;
			break;
		case 2:
			this->addJob();
			flag = false;
			break;
		case 3:
			this->findCategory();
			flag = false;
			break;
		case 4:
			system("cls");
			cout << "------------------------------------------------------------" << endl;
			cout << "\n";
			cout << "\n";
			this->showAllJobs();
			choice = this->showHomeMenu();
			break;
		case 5:
			cout << "请选择需要计算的工作(1.程序员 2.美工)";
			cin >> job_choice;
			system("cls");
			this->CalculateSalary(job_choice);
			choice = this->showHomeMenu();
			break;
		case 6:
			system("cls");
			flag = this->exitSystem();
			break;
		default:
			system("cls");
			cout << "您输入的项不存在，请重新选择...";
			cout << "\n";
			choice = this->showHomeMenu();
			break;
		}
	}
}
void SystemUI::findCategory()
{
	system("cls");
	cout << "------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\n";
	_dataProvider->show();
	cout << "------------------------------------------------------------" << endl;
	cout << "请输入您要检索的分类名称(虚线上方为分类名称，虚线下方第一个为工作名称)：";
	string name;
	cin >> name;
	system("cls");
	Category* categoryList = _dataProvider->FindByCategoryName(name);
	cout << "您要找的结果为：";
	cout << "\n";
	if (nullptr != categoryList)
	{
		categoryList->show();
		cout << "\n";
	}
	else
	{
		cout << "没有找到与您的输入相匹配的工作";
		cout << "\n";
	}
	this->showHomeMenuOperation();
}
void SystemUI::showLoginMeunOperation()
{
	string username;
	string userpassword;
	User* _user = new User();
	bool flag2 = true;
	//先检查当前状态
	while (flag2)
	{
		//TODO:完成登陆，注册功能
		int choice = this->showLoginMeun();
		switch (choice)
		{
		case 1:
			this->LoginOperation();
			continue;
		case 2:
			flag2 = this->exitSystem();
			break;
		default:
			system("cls");
			cout << "没有该项！请重新输入";
			cout << "\n";
			this->showLoginMeunOperation();
			cout << "\n";
			flag2 = false;
		}
	}
}
void SystemUI::addJob()
{
	system("cls");
	//添加工作
	cout << "请在如下区域输入Job相关信息：" << endl;
	string name;
	string desc;
	float salary = 0;
	string cmpName;
	string position;
	int id = 0;
	string category;
	Job* _job;
	cout << "工作ID:";
	cin >> id;
	if (cin.fail())
	{
		cout << "工作ID只能是int类型，请重新添加工作";
		cout << "\n";
	}
	else
	{
		cin.clear();
		cin.sync();
		cout << "工作名称:"; cin >> name;
		_job = _dataProvider->FindByName(name);
		if (_job == nullptr)
		{
			cout << "工作描述:"; cin >> desc;
			cout << "工作薪资(只能为数字):";
			cin >> salary;
			if (cin.fail())
			{
				cout << "工作薪资只能是float类型，请重新添加工作";
				cout << "\n";
			}
			else
			{
				cin.clear();
				cin.sync();
				cout << "公司名称:"; cin >> cmpName;
				cout << "职位:"; cin >> position;
				cout << "工作分类:"; cin >> category;
				Job *job = new Job(id, name, desc, salary, cmpName, position);
				_dataProvider->addJob(job, category);
				cout << "\n";
				system("cls");
				cout << "添加工作成功!";
				cout << "\n";
			}
		}
		else
		{
			system("cls");
			cout << "工作名称不能相同，请重新添加";
			cout << "\n";
		}
	}
	this->showHomeMenuOperation();
}
void SystemUI::findJob()
{
	system("cls");
	cout << "------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "\n";
	_dataProvider->show();
	cout << "------------------------------------------------------------" << endl;
	cout << "请输入要查看的工作名称(虚线上方为分类名称，虚线下方第一个为工作名称)：";
	string name;
	cin >> name;
	system("cls");
	cout << "查找结果：";
	cout << "\n";
	Job* result = _dataProvider->FindByName(name);
	if (nullptr != result)
	{
		result->show();
		cout << "\n";
	}
	else
	{
		cout << "没有找到与您的输入相匹配的工作";
		cout << "\n";
	}
	this->showHomeMenuOperation();
}
bool SystemUI::exitSystem()
{
	return false;
}
void SystemUI::LoginOperation()
{
	string username;
	string userpassword;
	User* _user = new User();
	bool flag2 = true;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> userpassword;
	_user = _dataProvider->Login(username, userpassword);
	if (_user != nullptr)
	{
		system("cls");
		cout << "登陆成功！";
		cout << "\n";
		this->showHomeMenuOperation();
		system("cls");
	}
	else
	{
		system("cls");
		cout << "登陆失败!请重新登陆";
		cout << "\n";
	}
}
void SystemUI::showAllJobs()
{
	_dataProvider->show();
}