#pragma once
#include "DataProvider.h"
#include "CategoryList.h"
class SystemUI
{
private:
	DataProvider* _dataProvider;
private:
	void LoginOperation();//��½����
	bool exitSystem();// �˳�ϵͳ
	void findJob();//���������ҹ���
	void addJob();//��ӹ���
	void findCategory();//���ݷ������Ʋ���
	void showAllJobs();//չʾ���й���
public:
	SystemUI();
	~SystemUI();
	/*�˵�����*/
public:
	void showHomeMenuOperation();//���˵�����
	void showLoginMeunOperation();//��½�˵�����
	int showHomeMenu();//չʾ���˵�
	int showLoginMeun();//չʾ��½�˵�
	void CalculateSalary(int);//���㹤��
};


