#pragma once
class Job
{
private:
	int _id;//����ID
	string _name;//��������
	string _description;//��������
	float _salary;//н��
	string _companyName;//��˾����
	string _position;//ְλ
	//Category* _category;
public:
	/*��ʼ��Job����,���������ǣ�
	 *���,
	 *��������,
	 *��������,
	 *нˮ
	 *��˾����,
	 *��Ƹְλ*/
	Job(int, string, string, float, string, string);
	Job();
	~Job();
public:
	string getName();//��ȡ��������
	void show();//չʾ����
};