#pragma once
#include "JobList.h"
/*Job分类*/
class Category
{
private:
	int _id;//分类ID
	string _name;//分类名称
	JobList* _jobs;//工作集合
public:
	Category(int, string);
	Category();
	~Category();
public:
	void show();//展示分类
	JobList* Jobs();//获得工作
public:
	string getName();//获取类别名称
};
