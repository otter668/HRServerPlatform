#pragma once
#include "Job.h"
class JobList
{
private:
	Job* _data;//工作
	int _count;//工作集合长度
	int _capacity;//工作集合最大容量
private:
	void resize();//扩充工作集合容量
public:
	JobList(int);
	~JobList();
public:
	void add(Job& job);//添加工作
	Job* get(int);//获取某个工作
	int Count();//获取工作集合长度
public:
	void show();//展示
};
