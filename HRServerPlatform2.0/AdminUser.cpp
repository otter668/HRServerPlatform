#include "AdminUser.h"


AdminUser::AdminUser(void)
{
}


AdminUser::AdminUser(string name, string pwd):User(name, pwd)
{

}

AdminUser::~AdminUser(void)
{
}

int AdminUser::getsalary()
{
	return 0;
}
