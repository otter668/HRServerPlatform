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
	cout << "1.�鿴��������(��������������)" << endl;
	cout << "2.��ӹ���" << endl;
	cout << "3.�鿴��������(��������������)" << endl;
	cout << "4.�鿴���й���" << endl;
	cout << "5.���㹤��" << endl;
	cout << "6.�˳�" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "��ѡ��";
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
		cout << "����Ա�Ĺ���Ϊ:" << _user1->getsalary();
		cout << "\n";
		break;
	case 2:
		cout << "�����Ĺ���Ϊ:" << _user2->getsalary();
		cout << "\n";
		break;
	default:
		cout << "�����ڸù������";
		cout << "\n";
		break;
	}
}
int SystemUI::showLoginMeun()
{
	cout << "-------------------------" << endl;
	cout << "1.��½" << endl;
	cout << "2.�˳�" << endl;
	cout << "-------------------------" << endl;
	cout << "��ѡ��" << endl;
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
			cout << "��ѡ����Ҫ����Ĺ���(1.����Ա 2.����)";
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
			cout << "�����������ڣ�������ѡ��...";
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
	cout << "��������Ҫ�����ķ�������(�����Ϸ�Ϊ�������ƣ������·���һ��Ϊ��������)��";
	string name;
	cin >> name;
	system("cls");
	Category* categoryList = _dataProvider->FindByCategoryName(name);
	cout << "��Ҫ�ҵĽ��Ϊ��";
	cout << "\n";
	if (nullptr != categoryList)
	{
		categoryList->show();
		cout << "\n";
	}
	else
	{
		cout << "û���ҵ�������������ƥ��Ĺ���";
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
	//�ȼ�鵱ǰ״̬
	while (flag2)
	{
		//TODO:��ɵ�½��ע�Ṧ��
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
			cout << "û�и������������";
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
	//��ӹ���
	cout << "����������������Job�����Ϣ��" << endl;
	string name;
	string desc;
	float salary = 0;
	string cmpName;
	string position;
	int id = 0;
	string category;
	Job* _job;
	cout << "����ID:";
	cin >> id;
	if (cin.fail())
	{
		cout << "����IDֻ����int���ͣ���������ӹ���";
		cout << "\n";
	}
	else
	{
		cin.clear();
		cin.sync();
		cout << "��������:"; cin >> name;
		_job = _dataProvider->FindByName(name);
		if (_job == nullptr)
		{
			cout << "��������:"; cin >> desc;
			cout << "����н��(ֻ��Ϊ����):";
			cin >> salary;
			if (cin.fail())
			{
				cout << "����н��ֻ����float���ͣ���������ӹ���";
				cout << "\n";
			}
			else
			{
				cin.clear();
				cin.sync();
				cout << "��˾����:"; cin >> cmpName;
				cout << "ְλ:"; cin >> position;
				cout << "��������:"; cin >> category;
				Job *job = new Job(id, name, desc, salary, cmpName, position);
				_dataProvider->addJob(job, category);
				cout << "\n";
				system("cls");
				cout << "��ӹ����ɹ�!";
				cout << "\n";
			}
		}
		else
		{
			system("cls");
			cout << "�������Ʋ�����ͬ�����������";
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
	cout << "������Ҫ�鿴�Ĺ�������(�����Ϸ�Ϊ�������ƣ������·���һ��Ϊ��������)��";
	string name;
	cin >> name;
	system("cls");
	cout << "���ҽ����";
	cout << "\n";
	Job* result = _dataProvider->FindByName(name);
	if (nullptr != result)
	{
		result->show();
		cout << "\n";
	}
	else
	{
		cout << "û���ҵ�������������ƥ��Ĺ���";
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
	cout << "�������û�����";
	cin >> username;
	cout << "���������룺";
	cin >> userpassword;
	_user = _dataProvider->Login(username, userpassword);
	if (_user != nullptr)
	{
		system("cls");
		cout << "��½�ɹ���";
		cout << "\n";
		this->showHomeMenuOperation();
		system("cls");
	}
	else
	{
		system("cls");
		cout << "��½ʧ��!�����µ�½";
		cout << "\n";
	}
}
void SystemUI::showAllJobs()
{
	_dataProvider->show();
}