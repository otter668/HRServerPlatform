#pragma once
#include "Job.h"
class JobList
{
private:
	Job* _data;//����
	int _count;//�������ϳ���
	int _capacity;//���������������
private:
	void resize();//���乤����������
public:
	JobList(int);
	~JobList();
public:
	void add(Job& job);//��ӹ���
	Job* get(int);//��ȡĳ������
	int Count();//��ȡ�������ϳ���
public:
	void show();//չʾ
};
