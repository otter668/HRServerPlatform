#include "stdafx.h"
#include "Category.h"
Category::Category(int id, string name) :_id(id), _name(name)
{
	_jobs = new JobList(16);
}

Category::Category()
{
	_id = 0;
	_jobs = new JobList(16);
}

Category::~Category()
{
	if (nullptr != _jobs)
	{
		delete _jobs;
		_jobs = nullptr;
	}
}
void Category::show()
{
	cout << _name << endl;
	cout << "------------------------------------------------------------" << endl;
	_jobs->show();
	cout << "\n";
}

JobList* Category::Jobs()
{
	return this->_jobs;
}
string Category::getName()
{
	return Category::_name;
}