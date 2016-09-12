#pragma once
#include "Category.h"
class CategoryList
{
private:
	Category* _data;//工作类别
	int _count;//类别集合长度
	int _capacity;//类别集合最大容量
private:
	void resize();//扩充类别集合容量
public:
	CategoryList(int);
	CategoryList();
	~CategoryList();
public:
	void add(Category& category);//添加分类
	Category* get(int);//获取某个分类
	int Count();//获取集合长度
public:
	void show();//展示类别集合
};
