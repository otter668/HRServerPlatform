#pragma once
#include "user.h"
class AdminUser :
	public User
{
public:
	AdminUser(void);
	AdminUser(string, string);
	~AdminUser(void);
public:
	int getsalary();//¼ÆËã¹¤×Ê
};

