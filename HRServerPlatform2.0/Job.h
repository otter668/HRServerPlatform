#pragma once
class Job
{
private:
	int _id;//工作ID
	string _name;//工作名称
	string _description;//工作描述
	float _salary;//薪资
	string _companyName;//公司名称
	string _position;//职位
	//Category* _category;
public:
	/*初始化Job对象,参数依次是：
	 *编号,
	 *工作名称,
	 *工作描述,
	 *薪水
	 *公司名称,
	 *招聘职位*/
	Job(int, string, string, float, string, string);
	Job();
	~Job();
public:
	string getName();//获取工作名称
	void show();//展示工作
};