#include "stdafx.h"
#include "Job.h"
	Job::Job(/*id*/int id,/*name*/string name,/*description*/string desc,
		/*salary*/float salary,/*companyName*/string cmpName,/*position*/string position) :_id(id), _name(name), _description(desc),
		_salary(salary), _companyName(cmpName), _position(position)
	{	
	}

	Job::Job()
	{

	}

	Job::~Job()
	{
		/*if (nullptr != _category)
		{
			delete _category;
			_category = nullptr;
		}*/
	}
	void Job::show()
	{
		cout << _name << "\t" << _companyName << "\t" << _position << "\t" << _salary << "\t" << endl;
	}
	string Job::getName()
	{
		return Job::_name;
	}