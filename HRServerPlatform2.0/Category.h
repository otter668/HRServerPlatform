#pragma once
#include "JobList.h"
/*Job����*/
class Category
{
private:
	int _id;//����ID
	string _name;//��������
	JobList* _jobs;//��������
public:
	Category(int, string);
	Category();
	~Category();
public:
	void show();//չʾ����
	JobList* Jobs();//��ù���
public:
	string getName();//��ȡ�������
};
