#pragma once
#include "Category.h"
class CategoryList
{
private:
	Category* _data;//�������
	int _count;//��𼯺ϳ���
	int _capacity;//��𼯺��������
private:
	void resize();//������𼯺�����
public:
	CategoryList(int);
	CategoryList();
	~CategoryList();
public:
	void add(Category& category);//��ӷ���
	Category* get(int);//��ȡĳ������
	int Count();//��ȡ���ϳ���
public:
	void show();//չʾ��𼯺�
};
